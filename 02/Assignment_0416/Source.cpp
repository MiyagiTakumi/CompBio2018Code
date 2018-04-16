// Assignment_0416.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int main() {
	const float x_ini = 100;	//初期個体数
	const float r = 2;	//Reproduction Rate
	const float k = 30000;	//Carrying Capacity

	
	/*｛（次の世代の個体数）ー（今の世代の個体数）の絶対値｝＜　Thr_Abs 
	が　Thr_Time　回連続すると平衡状態と判定*/
	const float Thr_Abs = 1000;
	const float Thr_Time = 100;


	float x_crnt = 0;	//今の世代の個体数
	float x_next = 0;	//次の世代の個体数
	int i = 2;	//世代数カウンター
	int Eq_Count = 0;

	x_crnt = x_ini;

	while (true) {
		x_next = x_crnt + r * (1 - x_crnt / k)*x_crnt;	//ロジスティックモデル

		if (unsigned(x_next - x_crnt) < Thr_Abs)
			Eq_Count++;
		else
			Eq_Count = 0;

		printf("第%d世代\t%f匹\n", i, x_next);
		i++;

		x_crnt = x_next;

		if (Eq_Count == Thr_Time)
			break;

		if (x_crnt <= 0) {
			x_crnt = 0;
			break;
		}
	}

	printf("初期個体数：%f\n増殖率：%f\n環境収容力：%f\n\n", x_ini, r, k);
	printf("次の世代との個体数の差が%f以下である場合が%f世代連続したとき平衡状態と判定\n\n", Thr_Abs, Thr_Time);
	printf("平衡状態での個体数：%f", x_crnt);

	return 0;
}