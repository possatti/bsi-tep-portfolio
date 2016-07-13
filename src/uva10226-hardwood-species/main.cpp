// UVa 10226 - Hardwood Species

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> // cin, cout, endl
#include <string> // string class
#include <map>  // map class

using namespace std;

typedef std::map<std::string, int>::iterator it_type;

int main() {
	int tc;

	// Read number of test cases.
	scanf("%d\n", &tc);
	// printf("==> %d\n", tc);
	scanf("\n");
	// printf("==> \n");

	// For each test case
	for (int i = 0; i < tc; ++i)
	{
		int n_trees = 0;
		map<string, int> tree_map;

		// Read trees
		string line;
		do {
			// Read tree name.
			getline(cin, line);
			// cout << "==> " << line << endl;
			// Add to the map.
			if (line != "") {
				// If it doesn't exist in the map yet.
				if (tree_map.find(line) == tree_map.end()) {
					tree_map[line] = 1;
				// If it exists already.
				} else {
					tree_map[line] += 1;
				}
				n_trees += 1;
			}
		} while (line != "");
		// cout << "DEBUG: Finished reading." << endl;

		// DEBUG:
		// printf("DEBUG: n_trees = %d\n", n_trees);
		// printf("DEBUG: tree_map:\n");
		// for(it_type iterator = tree_map.begin(); iterator != tree_map.end(); iterator++) {
		// 	cout << "DEBUG:   " << iterator->first << ": " << iterator->second << endl;
		// }

		// Print answer.
		for(it_type iterator = tree_map.begin(); iterator != tree_map.end(); iterator++) {
			double percentage = (float) iterator->second / (float) n_trees;
			// printf("DEBUG: percentage = %f\n", percentage*100);
			// printf("DEBUG: percentage = %.4f\n", percentage*100);
			// cout << "DEBUG: " << iterator->first << ": " << percentage << endl;
			cout << iterator->first;
			printf(" %.4f\n", percentage*100);
		}
		if (i != tc-1) {
			printf("\n");
		}
	}

	return 0;
}
