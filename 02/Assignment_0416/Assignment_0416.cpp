// Assignment_0416.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int main() {
	float x_ini = 0;	//Initial Population
	float r = 0;	//Reproduction Rate
	float k = 0;	//Carrying Capacity

	char Judge;

	STARTPOINT:

	do {
		printf("Enter the Initial Population (X1)\n");
		scanf_s("%d", x_ini);
	} while (x_ini <= 0);

	do {
		printf("Enter the Reproduction Rate (r)\n");
		scanf_s("%f", r);
	} while (r <= 0);

	do {
		printf("Enter the Carrying Capacity (K)\n");
		scanf_s("%f", k);
	} while (k <= 0);


	do {
		printf("X1 = %d, r = %f, K = %f\n", x_ini, r, k);
		printf("Start calculation?\nEnter y or n\n");
		scanf_s("%c", &Judge);
	} while (Judge != 'y' && Judge != 'n');

	if (Judge == 'n')
		goto STARTPOINT;



	float x_crnt, x_next;	//今の世代の人口、次の世代の人口
	int Eq_count;	//平衡に達したか判定するカウンター変数
	const float thr;	//平衡に達したか判定する閾値

	x_crnt = x_ini;

	while (true) {
		x_next = x_crnt + r * (1 - x_crnt / k)*x_crnt;	//ロジスティックモデル
		
		if( unsigned(x_next-x_crnt) < )
	}

}

