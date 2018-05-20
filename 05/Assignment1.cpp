#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int main() {
	unsigned int trial = 0;
	unsigned int sum1 = 0, sum2 = 0;
	unsigned int result[1000] = { 0 };
	unsigned int elementnumber[5] = { 1,5,10,100,1000 };

	srand(time(NULL));


	for (int i = 0; i < 1000; i++) {
		sum1 = 0;
		trial = 0;

		do {
			sum1 += rand() % 6 + 1;
			trial++;
		} while (sum1 < 100);

		result[i] = trial;
	}


	for (int i = 0; i < 5; i++) {

		sum2 = 0;

		for (int j = 0; j < elementnumber[i]; j++) {
			sum2 += result[j];
		}

		cout << "average of " << setw(4)<< left << elementnumber[i] << " data: " << float(sum2) / elementnumber[i] << endl;

	}
		return 0;
}