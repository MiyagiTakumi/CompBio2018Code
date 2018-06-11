#include <iostream>
#include <fstream>
using namespace std;


const unsigned int CELL_NUM = 100;
const unsigned int RULE_NUM = 90; //Max:255
const unsigned int TRIAL_NUM = 100;


bool pattern[8] = { false };
bool TempCell[CELL_NUM] = { false };
bool NextCell[CELL_NUM] = { false };


void rule(bool* TempCell,bool* NextCell, int TempNum);

int main() {

	TempCell[int(CELL_NUM / 2)] = true;

	unsigned int judge = RULE_NUM;

	for (int i = 7; i >= 0; i--) {

		if (judge >= unsigned int(pow(2, i))) {
			pattern[i] = true;
			judge -= unsigned int(pow(2, i));
		}
		else if (judge < unsigned int(pow(2, i)))
			pattern[i] = false;

		else {
			cout << "exception1" << endl;
			return -1;
		}
	}


	ofstream fout("Assignment1.csv");

	for (int i = 0; i < CELL_NUM; i++) {
		if (i == CELL_NUM - 1) 
			fout << TempCell[i] << endl;

		else
			fout << TempCell[i] << ',';
	}

	for (int j = 0; j < TRIAL_NUM; j++) {

		for (int Num = 0; Num < CELL_NUM; Num++) {
			rule(TempCell, NextCell, Num);

			if (Num == CELL_NUM - 1)
				fout << NextCell[Num] << endl;

			else
				fout << NextCell[Num] << ',';
		}

		for (int i = 0; i < CELL_NUM; i++) {
			TempCell[i] = NextCell[i];
		}
	}

	fout.close();

	return 0;
}

void rule(bool* TempCell,bool* NextCell, int Num) {
	unsigned int point;

	if (Num == 0)
		point = 4 * TempCell[CELL_NUM - 1] + 2 * TempCell[Num] + TempCell[Num + 1];

	else if (Num == CELL_NUM - 1)
		point = 4 * TempCell[Num - 1] + 2 * TempCell[Num] + TempCell[0];

	else
		point = 4 * TempCell[Num - 1] + 2 * TempCell[Num] + TempCell[Num + 1];

	if (point < 0 || 7 < point) {
		cout << "exception2" << endl;
		exit(1);
	}

	NextCell[Num] = pattern[point];
}