#include "stdafx.h"


int main() {
	const long x_ini = 100;	//第１世代個体数
	float r = 0;
	const float MIN_r = 1.0;	//最低増殖率
	const float MAX_r = 3.0;	//最大増殖率
	const long double k = 30000;	//環境収容力
	const int MAX_GEN = 300;	//最大世代数
	int x_crnt = 0;	//今の世代の個体数
	int x_next = 0;	//次の世代の個体数

	int x[300];

	FILE* fp;
	errno_t eCode = fopen_s(&fp, "bunki.csv", "w");

	for (int j = 0; j <= 100; j++) {
		fprintf(fp, ",t=%d", j + 200);
	}

	fprintf(fp, "\n");

	for (int rx1000 = 1000 * MIN_r; rx1000 < 1000 * MAX_r; rx1000++) {

		x_crnt = x_ini;
		r = float(rx1000) / 1000;

		for (int i = 2; i <= MAX_GEN; i++) {

			x_next = int(x_crnt + r * (1 - x_crnt / k)*x_crnt);	//ロジスティックモデル

			if (i >= 200) {
				x[i - 200] = x_next;
			}

		
			if (x_next < 1) {
				break;
			}

			x_crnt = x_next;
		}

		fprintf(fp, "r=%2f,", r);

		for (int k = 0; k < 100; k++) {
			fprintf(fp, "%d,", x[k]);
		}

		fprintf(fp, "%d\n", x[100]);
	}

	fclose(fp);
	return 0;
}