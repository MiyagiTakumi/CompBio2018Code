#include <iostream>
#include <random>
using namespace std;

int main() {
	const int N = 1000;	//Population
	const float p = 0.2;	//Initial frequency of Mutation Allele

	bool GenePool_crnt[2 * N] = { false };
	bool GenePool_next[2 * N] = { false };

	unsigned int Generation_log[100] = { 0 };

	unsigned int Generation = 0;
	unsigned int sum1 = 0, sum2 = 0;


	int a;	//2*N*p Rounded to the nearest int

	if (int(2 * N*p) + 0.5 < 2 * N*p)
		a = int(2 * N*p) + 1;
	else
		a = int(2 * N*p);


	random_device SeedGen;	//Seed Generator
	mt19937 MT(SeedGen());	//Merscenne_Twisster


	for (int j = 0; j < 100; j++) {
	restart:

		//Initialize
		
		for (int i = 0; i < 2 * N; i++) {
			GenePool_crnt[i] = false;
			GenePool_next[i] = false;
		}
		for (int i = 0; i < a; i++) {
			GenePool_crnt[i] = true;
		}

		Generation = 0;
		


		//Generation count
		do {
			sum1 = 0;

			for (int i = 0; i < 2 * N; i++) {
				GenePool_next[i] = GenePool_crnt[MT() % (2 * N)];
			}

			for (int i = 0; i < 2 * N; i++) {
				GenePool_crnt[i] = GenePool_next[i];
			}

			for (int i = 0; i < 2 * N; i++) {
				sum1 += GenePool_next[i];
			}

			Generation++;

		} while (0 < sum1&&sum1 < 2 * N);

		if (sum1 == 0)	//if Mutation Allele is extinguished
			goto restart;

		else if (sum1 == 2 * N)	//if Mutation Allele is immobilized
			Generation_log[j] = Generation;
	}

	for (int i = 0; i < 100; i++) {
		sum2 += Generation_log[i];
	}

	cout << "Average Genaration spent till the Allele is immobilized:" << float(sum2) / 100 << endl;

	return 0;
}