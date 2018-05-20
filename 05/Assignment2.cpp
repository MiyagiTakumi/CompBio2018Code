#include <iostream>
#include <fstream>

using namespace std;


const int Objective_SUM = 100;
int Dice[Objective_SUM + 1] = { 0 };	//Dice[t] = the result of "t"th dice trial
int sum = 0;						//sum of Dice result (Dice[1] + Dice[2] + ... + Dice[t]
int t = 1;							//"t"th dice trial


unsigned long long Event_SUM[Objective_SUM + 1] = { 0 };	//Event_SUM[t] = the number of event when sum reached "Objective_SUM" by "t"th dice trial


void unit() {
	for (Dice[t] = 1; Dice[t] <= 6; Dice[t]++) {

		sum += Dice[t];

		if (sum >= Objective_SUM) {
			Event_SUM[t]++;

			sum -= Dice[t];

			continue;
		}

		else {
			t++;

			unit();

			t--;
			sum -= Dice[t];
		}
	}

	return;
}

int main() {

	unit();

	ofstream fout("Assignment2.csv");

	for (int j = 1; j <= Objective_SUM; j++) {

		int i = 0;


		fout << j << "," << Event_SUM[j] << endl;

	}

	fout.close();

	return 0;
}