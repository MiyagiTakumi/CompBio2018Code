#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
	double x_crnt = 0;	//x(t)
	double x_next = 0;	//x(t + Δt)

	const double x_0 = 100;	//x(0) 

	const float r = 2.0;	//増殖率
	const float K = 10000;	//環境収容力

	const double accuracy = pow(10, 7);	// 1/Δt
	const double dt = 1 / accuracy;	//Δt

	const double t = 50;	//求めたいx(t)のt


	x_crnt = x_0;

	for (long i = 0; i < t * accuracy; i++) {

		x_next = x_crnt + dt * r * (1 - x_crnt / K) * x_crnt;

		x_crnt = x_next;
	}

	cout << "x(" << t << ") = " << x_crnt << endl;

	return 0;
}