#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
	/*parameter below*/
	double t = 50;	//The value of "t" to get S(t) & I(t)

	const double b = 0.001;	//Infection rate
	const double c = 0.2;	//Recovery and Removal rate

	const double S_ini = 800;	//Initial Susceptible population
	const double I_ini = 50;	//Initial Infectious population
	const double R_ini = 20;	//Initial Recovered or Removed population

	const double accuracy = pow(10, 4);
	const double dt = 1 / accuracy;

	const double sigma = 5.0;
	/*parametor end*/


	struct Population {
		double S;
		double I;
		double R;
	};

	Population current = { S_ini, I_ini, R_ini };
	Population next = { 0 };

	
	ofstream fout("Assignment3.csv");
	if (fout.bad())
		cout << "ofstream error" << endl;



	random_device seedgen;
	mt19937 mt(seedgen());
	normal_distribution<double> errdist(0, sigma);


	fout << "t,S,I,R" << endl;
	fout << 0 << "," << current.S + errdist(mt) << "," << current.I + errdist(mt) << "," << current.R + errdist(mt) << endl;

	for (int i = 1; i <= t*accuracy; i++) {
		next.S = (-b * current.S * current.I)*dt + current.S;
		next.I = (b * current.S * current.I - c * current.I)*dt + current.I;
		next.R = (c * current.I)*dt + current.R;

		if (i % int(accuracy) == 0) {
			fout << i/accuracy << "," << next.S + errdist(mt) << "," << next.I + errdist(mt) << "," << next.R + errdist(mt) << endl;
		}
		current = next;
	}

	fout.close();

	return 0;
}