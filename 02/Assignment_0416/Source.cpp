// Assignment_0416.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


int main() {
	const float x_ini = 100;	//�����̐�
	const float r = 2;	//Reproduction Rate
	const float k = 30000;	//Carrying Capacity

	
	/*�o�i���̐���̌̐��j�[�i���̐���̌̐��j�̐�Βl�p���@Thr_Abs 
	���@Thr_Time�@��A������ƕ��t��ԂƔ���*/
	const float Thr_Abs = 1000;
	const float Thr_Time = 100;


	float x_crnt = 0;	//���̐���̌̐�
	float x_next = 0;	//���̐���̌̐�
	int i = 2;	//���㐔�J�E���^�[
	int Eq_Count = 0;

	x_crnt = x_ini;

	while (true) {
		x_next = x_crnt + r * (1 - x_crnt / k)*x_crnt;	//���W�X�e�B�b�N���f��

		if (unsigned(x_next - x_crnt) < Thr_Abs)
			Eq_Count++;
		else
			Eq_Count = 0;

		printf("��%d����\t%f�C\n", i, x_next);
		i++;

		x_crnt = x_next;

		if (Eq_Count == Thr_Time)
			break;

		if (x_crnt <= 0) {
			x_crnt = 0;
			break;
		}
	}

	printf("�����̐��F%f\n���B���F%f\n�����e�́F%f\n\n", x_ini, r, k);
	printf("���̐���Ƃ̌̐��̍���%f�ȉ��ł���ꍇ��%f����A�������Ƃ����t��ԂƔ���\n\n", Thr_Abs, Thr_Time);
	printf("���t��Ԃł̌̐��F%f", x_crnt);

	return 0;
}