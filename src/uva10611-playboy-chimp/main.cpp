// UVa 10611 - Playboy Chimp

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> // cin, cout, endl
#include <string> // string class
#include <map>  // map class

using namespace std;

int TALLEST_HEIGHT = 2147483647;

int chimps[50000+1];
int queries[25000+1];
int N, Q;
int pc_height;

int main() {
	// Read data.
	scanf("%d\n", &N);
	for (int i = 0; i < N; ++i) {
		int chimp_height;
		scanf(" %d ", &chimp_height);
		chimps[i] = chimp_height;
	}
	scanf("%d\n", &Q);
	for (int i = 0; i < Q; ++i) {
		int querie;
		scanf(" %d ", &querie);
		queries[i] = querie;
	}

	// For each query.
	for (int i = 0; i < Q; ++i) {
		pc_height = queries[i];
		int smaller=0, taller=TALLEST_HEIGHT;
		bool smaller_b, taller_b;

		// Find smaller one.
		for (int j = 0; j < N; ++j) {
			if (chimps[j] > pc_height) {
				break;
			}
			if (chimps[j] > smaller && chimps[j] != pc_height) {
				smaller = chimps[j];
			}
		}

		// Find taller one.
		for (int j = N-1; j >= 0; --j) {
			// printf("DEBUG: chimps[%d]=%d\n", j, chimps[j]);
			if (chimps[j] < pc_height) {
				break;
			}
			if (chimps[j] < taller && chimps[j] != pc_height) {
				taller = chimps[j];
			}
		}

		// Print answer.
		if (smaller == 0) {
			printf("X %d\n", taller);
		} else if (taller == TALLEST_HEIGHT) {
			printf("%d X\n", smaller);
		} else
		printf("%d %d\n", smaller, taller);
	}

	return 0;
}
