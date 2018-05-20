#include <iostream>
#include <random>
#include <fstream>
using namespace std;

int main() {
	int N;	//Population
	float K;	//Population of Mutant Homozygote

	bool* GenePool_crnt;
	bool* GenePool_next;

	const int trial_limit = 100;

	unsigned int Generation_log[trial_limit] = { 0 };

	unsigned int Generation = 0;
	unsigned int sum1 = 0, sum2 = 0;


	random_device SeedGen;	//Seed Generator
	mt19937 MT(SeedGen());	//Merscenne_Twisster

	ofstream fout("Assignment6_plus.csv");
	if (fout.bad()) {
		cout << "fstream Error" << endl;
		return -1;
	}

	N = 10;

label:

	K = float(N) / 10;

	try {
		GenePool_crnt = new bool[N];
	}
	catch (bad_alloc) {
		cout << "GenePool_crnt Allocation failed" << endl;
		return -1;
	}

	try {
		GenePool_next = new bool[N];
	}
	catch (bad_alloc) {
		cout << "GenePool_next Allocation failed" << endl;
		return -1;
	}


	for (int k = 0; k < 10; k++) {
		for (int j = 0; j < trial_limit; j++) {
		restart:


			//Initialization
			for (int i = 0; i < N; i++) {
				GenePool_crnt[i] = false;
				GenePool_next[i] = false;
			}
			for (int i = 0; i < K; i++) {
				GenePool_crnt[i] = true;
			}

			Generation = 0;



			//Generation count
			do {
				sum1 = 0;

				for (int i = 0; i < N; i++) {
					GenePool_next[i] = GenePool_crnt[MT() % N];
				}

				for (int i = 0; i < N; i++) {
					GenePool_crnt[i] = GenePool_next[i];
				}

				for (int i = 0; i < N; i++) {
					sum1 += GenePool_next[i];
				}

				Generation++;

			} while (0 < sum1&&sum1 < N);

			if (sum1 == 0) 	//if Mutation Allele is extinguished
				goto restart;

			else if (sum1 == N) 	//if Mutation Allele is immobilized
				Generation_log[j] = Generation;

		}


		for (int i = 0; i < trial_limit; i++) {
			sum2 += Generation_log[i];
		}

		fout << K << "," << float(sum2) / trial_limit << endl;

		K += float(N) / 10;
		sum2 = 0;

	}

	delete[] GenePool_crnt;
	delete[] GenePool_next;

	if (N == 10) {
		N = 1000;
		goto label;
	}

	fout.close();
	return 0;
}