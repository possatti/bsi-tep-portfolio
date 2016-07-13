// UVa 10684 - The jackpot

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> // cin, cout, endl
#include <string> // string class
#include <map>  // map class

using namespace std;

int main() {
	int streak_len = -1;

	while (streak_len != 0) {
		// Read streak sequence.
		scanf("%d\n", &streak_len);
		// printf("DEBUG: streak_len=%d\n", streak_len);
		int streak[streak_len];
		if (streak_len == 0) {
			break;
		}
		for (int i = 0; i < streak_len; ++i) {
			int number;
			scanf(" %d ", &number);
			// printf("DEBUG: number=%d\n", number);
			streak[i] = number;
		}

		// DEBUG:
		// printf("DEBUG: streak:");
		// for (int i = 0; i < streak_len; ++i)
		// {
		// 	printf(" %d", streak[i]);
		// }
		// printf("\n");

		// Calculate sums.
		int results[streak_len];
		for (int i = 0; i < streak_len; ++i) {
			int sum = 0;
			for (int j = 0; j < i+1; ++j) {
				sum += streak[j];
			}
			results[i] = sum;
			// printf("DEBUG: sum=%d\n", sum);
		}

		// Find the maximum winning streak.
		int best_bet=-2147483647;
		for (int i = 0; i < streak_len; ++i) {
			if (results[i] > best_bet) {
				best_bet = results[i];
			}
		}

		// Print the verdict.
		if (best_bet <= 0) {
			printf("Losing streak.\n");
		} else {
			printf("The maximum winning streak is %d.\n", best_bet);
		}

		// printf("DEBUG: ===============\n");
	}
	return 0;
}
