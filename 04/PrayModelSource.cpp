#include <iostream>
#include <math.h>

using namespace std;


int main() {
	const float a = 1;
	const float b = 100;
	const float c = 100;
	const float d = 1;

	const double x1_ini = 1;
	const double x2_ini = 1;

	long double x_crnt[2] = { x1_ini, x2_ini };
	long double x_next[2] = { 0 };

	const long double accuracy = pow(10, 3);
	const long double dt = 1 / accuracy;


	FILE* fp;
	errno_t eCode = fopen_s(&fp, "Pray_result.csv", "w");

	if (eCode != 0) {
		cout << "fopen error" << endl;
		return 0;
	}

	fprintf(fp, "%f,%f,%f\n", float(0), x1_ini, x2_ini);


	for (int i = 1; i <= 300 * accuracy; i++) {

		x_next[0] = x_crnt[0] + (a - b * x_crnt[0])* x_crnt[0] * dt;
		x_next[1] = x_crnt[1] + (c - d * x_crnt[1])* x_crnt[1] * dt;

		if (i%long(accuracy) == 0) {
			fprintf(fp, "%f,%f,%f\n", i / accuracy, x_next[0], x_next[1]);
		}

		if (x_next[0] <= 0 || x_next[1] <= 0)
			break;

		x_crnt[0] = x_next[0];
		x_crnt[1] = x_next[1];

	}

	fclose(fp);

	return 0;
}