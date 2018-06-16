#include <iostream>
#include <random>
#include <fstream>

using namespace std;

const unsigned int X_range = 100;
const unsigned int Y_range = 100;
const unsigned int MAX_GENERATION = 100;


bool TempCell[X_range][Y_range] = { false };
bool NextCell[X_range][Y_range] = { false };

void step(int x, int y) {
	unsigned int sum = 0;
	unsigned int a = 0, b = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			/*loop process for edge of world*/
			if (x - 1 + i > int(X_range) - 1)
				a = 0;
			else if (x - 1 + i < 0)
				a = X_range - 1;
			else
				a = x - 1 + i;

			if (y - 1 + i > int(Y_range - 1))
				b = 0;
			else if (y - 1 + i < 0)
				b = Y_range - 1;
			else
				b = y - 1 + i;


			sum += TempCell[a][b];
		}
	}

	if (sum <= 1)
		NextCell[x][y] = false;

	else if (sum == 2)
		NextCell[x][y] = TempCell[x][y];

	else if (sum == 3)
		NextCell[x][y] = true;

	else if (sum >= 4)
		NextCell[x][y] = false;

	else {
		cerr << "unexpected sum value" << endl;
		exit(EXIT_FAILURE);
	}
};

int main() {
	random_device rd;
	mt19937 MT(rd());

	ofstream fout("LifeGame_result.csv");
	
	/*Initialization*/
	for (int x = 0; x < X_range; x++) {
		for (int y = 0; y < Y_range; y++) {
			TempCell[x][y] = (MT() % 2);
		}
	}


	for (int i = 0; i < MAX_GENERATION; i++) {

		/*generation transfer*/
		for (int x = 0; x < X_range; x++) {
			for (int y = 0; y < Y_range; y++) {
				step(x, y);
			}
		}

		/*data output*/
		for (int x = 0; x < X_range; x++) {
			for (int y = 0; y < Y_range; y++) {
				fout << NextCell[x][y];

				if (y != Y_range - 1)
					fout << ',';
			}

			fout << endl;
		}

		/*array initialization*/
		for (int x = 0; x < X_range; x++) {
			for (int y = 0; y < Y_range; y++) {
				TempCell[x][y] = NextCell[x][y];
			}
		}
		
	}

	fout.close();

	return 0;
}
