#include "stdafx.h"
#include <string>

void simulate(const long x_ini, const float r, const long double k, const int MAX_GEN) {

	int x_crnt = 0;	//今の世代の個体数
	int x_next = 0;	//次の世代の個体数


	x_crnt = x_ini;


	std::string FILENAME;
	FILENAME = "result_r=" + std::to_string(r) + ".txt";

	const char* FILENAME_array = FILENAME.c_str();

	FILE* fp;
	errno_t eCode = fopen_s(&fp, FILENAME_array, "w");

	fprintf(fp, "第  1世代\t%d匹\n", x_ini);

	for (int i = 2; i < MAX_GEN; i++) {

		x_next = int(x_crnt + r * (1 - x_crnt / k)*x_crnt);	//ロジスティックモデル

		fprintf(fp, "第%3d世代\t%d匹\n", i, x_next);

		if (x_next < 1) {
			break;
		}
	
		x_crnt = x_next;
	}

	fclose(fp);

}

int main() {
	const long x_ini = 100;	//第１世代個体数
	const float MIN_r = 1.0;	//最低増殖率
	const float MAX_r = 10;	//最大増殖率
	const long double k = 30000;	//環境収容力
	const int MAX_GEN = 300;	//最大世代数

	for (float r = MIN_r; r < MAX_r; r += 0.1) {
		simulate(x_ini, r, k, MAX_GEN);
	}

	return 0;
}