// UVa 00102 - Ecological Bin Packing

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> // cin, cout, endl
#include <string> // string class
#include <map>  // map class

using namespace std;

int b1_g, b1_b, b1_c;
int b2_g, b2_b, b2_c;
int b3_g, b3_b, b3_c;

typedef map<string, int> msi;
typedef msi::iterator msi_it;

int BCG() {
	int moves = 0;
	moves += b1_g + b1_c; // B
	moves += b2_g + b2_b; // C
	moves += b3_b + b3_c; // G
	return moves;
}
int BGC() {
	int moves = 0;
	moves += b1_g + b1_c; // B
	moves += b2_b + b2_c; // G
	moves += b3_g + b3_b; // C
	return moves;
}
int CBG() {
	int moves = 0;
	moves += b1_g + b1_b; // C
	moves += b2_g + b2_c; // B
	moves += b3_b + b3_c; // G
	return moves;
}
int CGB() {
	int moves = 0;
	moves += b1_g + b1_b; // C
	moves += b2_b + b2_c; // G
	moves += b3_g + b3_c; // B
	return moves;
}
int GBC() {
	int moves = 0;
	moves += b1_b + b1_c; // G
	moves += b2_g + b2_c; // B
	moves += b3_g + b3_b; // C
	return moves;
}
int GCB() {
	int moves = 0;
	moves += b1_b + b1_c; // G
	moves += b2_g + b2_b; // C
	moves += b3_g + b3_c; // B
	return moves;
}

int main() {
	int err;

	// Read data.
	err = scanf("%d %d %d ", &b1_b, &b1_g, &b1_c);
	err = scanf("%d %d %d ", &b2_b, &b2_g, &b2_c);
	err = scanf("%d %d %d ", &b3_b, &b3_g, &b3_c);

	// printf("DEBUG: ");
	// printf("%d %d %d ", b1_g, b1_b, b1_c);
	// printf("%d %d %d ", b2_g, b2_b, b2_c);
	// printf("%d %d %d ", b3_g, b3_b, b3_c);
	// printf("\n");

	while (err > 0) {

		msi combinations;
		combinations["BCG"] = BCG();
		combinations["BGC"] = BGC();
		combinations["CBG"] = CBG();
		combinations["CGB"] = CGB();
		combinations["GBC"] = GBC();
		combinations["GCB"] = GCB();

		// Search for the smallest one
		string order = "";
		int min_moves = 2147483647;
		for (msi_it it = --combinations.end(); it != --combinations.begin(); it--) {
			if (it->second <= min_moves) {
				order = it->first;
				min_moves = it->second;
			}
			// printf("DEBUG: %s = %d\n", it->first.c_str(), it->second);
		}
		printf("%s %d\n", order.c_str(), min_moves);

		// Read data.
		err = scanf("%d %d %d ", &b1_b, &b1_g, &b1_c);
		err = scanf("%d %d %d ", &b2_b, &b2_g, &b2_c);
		err = scanf("%d %d %d ", &b3_b, &b3_g, &b3_c);

		// printf("DEBUG: ");
		// printf("%d %d %d ", b1_g, b1_b, b1_c);
		// printf("%d %d %d ", b2_g, b2_b, b2_c);
		// printf("%d %d %d ", b3_g, b3_b, b3_c);
		// printf("\n");
	}

	return 0;
}
