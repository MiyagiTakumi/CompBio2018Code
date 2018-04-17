#include "stdafx.h"
#include <string>

void simulate(const long x_ini, const float r, const long double k, const int MAX_GEN) {

	int x_crnt = 0;	//���̐���̌̐�
	int x_next = 0;	//���̐���̌̐�


	x_crnt = x_ini;


	std::string FILENAME;
	FILENAME = "result_r=" + std::to_string(r) + ".txt";

	const char* FILENAME_array = FILENAME.c_str();

	FILE* fp;
	errno_t eCode = fopen_s(&fp, FILENAME_array, "w");

	fprintf(fp, "��  1����\t%d�C\n", x_ini);

	for (int i = 2; i < MAX_GEN; i++) {

		x_next = int(x_crnt + r * (1 - x_crnt / k)*x_crnt);	//���W�X�e�B�b�N���f��

		fprintf(fp, "��%3d����\t%d�C\n", i, x_next);

		if (x_next < 1) {
			break;
		}
	
		x_crnt = x_next;
	}

	fclose(fp);

}

int main() {
	const long x_ini = 100;	//��P����̐�
	const float MIN_r = 1.0;	//�Œᑝ�B��
	const float MAX_r = 10;	//�ő呝�B��
	const long double k = 30000;	//�����e��
	const int MAX_GEN = 300;	//�ő吢�㐔

	for (float r = MIN_r; r < MAX_r; r += 0.1) {
		simulate(x_ini, r, k, MAX_GEN);
	}

	return 0;
}