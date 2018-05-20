#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main() {
	int position = 0; 
	int pos_log[100] = { 0 };

	srand(time(NULL));
	
	fstream fout;

	fout.open("Assignment3.csv", ios::out);


	for (int j = 0; j < 5; j++) {
		position = 0;

		for (int i = 1; i <= 99; i++) {
			if (rand() % 2)
				position++;
			else
				position--;

			pos_log[i] = position;
		}

		for (int i = 0; i < 99; i++) {
			fout << pos_log[i] << "," << flush;
		}

		fout << pos_log[99] << endl;

	}

	fout.close();

	return 0;
}