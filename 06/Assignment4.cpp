#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	const double accuracy = pow(10, 5); //accuracy of Newton's method
	const unsigned int range = 5;	//consider I(0) to I(range) is initial stage of infection

	string line;
	int pos_L_com, pos_R_com; 
	size_t n_of_char = 0;

	string tempstr;

	float I[11] = { 0 };


	double lambda = 0;
	double V_diff = 0;
	double V_diff_diff = 0;


	ifstream fin("Assignment3.csv");
	if (fin.fail()) {
		cerr << "File open failed" << endl;
		return -1;
	}



	fin.ignore(256, '\n');

	for (int t = 0; t <= 10; t++) {
		getline(fin, line);


		/*detecting I's cell*/
		pos_L_com = -1;	//for convenience, consider that -1 th character of "line" is "," 
		pos_R_com = line.find(",");

		pos_L_com = pos_R_com;
		pos_R_com = line.find(",", pos_L_com + 1);

		pos_L_com = pos_R_com;
		pos_R_com = line.find(",", pos_L_com + 1);
		/*moved to I's cell*/

		n_of_char = pos_R_com - pos_L_com - 1;

		tempstr = line.substr(pos_L_com + 1, n_of_char);	//reading I as string

		I[t] = stof(tempstr);	//converting I contained in "tempstr" into float 

	}

	lambda = (log(I[range]) - log(I[0])) / range;


	do{
		V_diff = 0;
		V_diff_diff = 0;

		for (int t = 0; t <= range; t++) {
			V_diff += -2 * I[0] * t*I[t] * exp(t*lambda) + 2 * I[0] * I[0] * t*exp(2 * t*lambda);
			V_diff_diff += -2 * I[0] * t*t*I[t] * exp(t*lambda) + 4 * I[0] * I[0] * t*t*exp(2 * t*lambda);
		}

		lambda = lambda - V_diff / V_diff_diff;

	} while (V_diff < -1 / accuracy || 1 / accuracy < V_diff);

	cout << "estimated lambda = " << lambda << endl;

	fin.close();

	return 0;
}