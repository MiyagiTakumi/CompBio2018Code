#include <iostream>
#include <math.h>

using namespace std;


int main() {
	const float a = 100;
	const float b = 20;
	const float c = 10;
	const float d = 100;
	const float e = 30;
	const float f = 10;

	const double x1_ini = 1;
	const double x2_ini = 1;

	long double x_crnt[2] = { x1_ini, x2_ini };
	long double x_next[2] = { 0 };

	const long double accuracy = pow(10, 3);
	const long double dt = 1 / accuracy;


	FILE* fp;
	errno_t eCode = fopen_s(&fp, "Symb_result.csv", "w");

	if (eCode != 0)
		cout << "fopen error" << endl;

	fprintf(fp, "%f,%f,%f\n", float(0), x1_ini, x2_ini);


	for (int i = 1; i <= accuracy; i++) {

		x_next[0] = x_crnt[0] + (a - b * x_crnt[0] + c * x_crnt[1])* x_crnt[0] * dt;
		x_next[1] = x_crnt[1] + (d + e * x_crnt[0] - f * x_crnt[1])* x_crnt[1] * dt;

		fprintf(fp, "%f,%f,%f\n", i / accuracy, x_next[0], x_next[1]);

		x_crnt[0] = x_next[0];
		x_crnt[1] = x_next[1];

	}

	fclose(fp);

	return 0;
}