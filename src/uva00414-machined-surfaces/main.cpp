// UVa 00414 - Machined Surfaces

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const char space_ch = ' ';

int count_spaces(string s) {
	int count = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == space_ch)
			count++;
	}
	return count;
}

int main() {
	int nl; // number of lines
	string line;
	vector<int> spaces;

	// Read number of lines
	scanf("%d\n", &nl);

	while (nl != 0) {
		spaces.resize(0);

		// Read test case lines and count spaces
		for (int i = 0; i < nl; ++i) {
			getline(cin, line);
			spaces.push_back(count_spaces(line));
		}

		// Search for the smaller gap
		int min_gap = 26;
		for (int i = 0; i < spaces.size(); ++i) {
			if (spaces[i] < min_gap)
				min_gap = spaces[i];
		}

		// Subtract the minimum gap from all of the gaps
		for (int i = 0; i < spaces.size(); ++i) {
			spaces[i] -= min_gap;
		}

		// Sum up how many spaces are left after joining the peaces
		int total_void = 0;
		for (int i = 0; i < spaces.size(); ++i) {
			total_void += spaces[i];
		}

		// Print the total
		cout << total_void << endl;

		// Read number of lines for the next test case
		scanf("%d\n", &nl);
	}

	return 0;
}
