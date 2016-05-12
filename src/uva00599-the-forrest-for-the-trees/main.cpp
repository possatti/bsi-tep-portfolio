// UVa 00599 - The forrest for the trees

#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, char> cc;
typedef vector<cc> vcc;
typedef vector<char> vc;

int n; // Number of test cases
vc v; // Vertices
vcc e; // Edges
vector<vc> trees; // Vertices of trees
int nt, na; // Number of trees and acorns
char c1, c2; // Used to read the vertices of edges from stdin

// Which tree that vertice belongs to
int belongs_to(char c) {
	for (int i = 0; i < trees.size(); ++i) {
		if (find(trees[i].begin(), trees[i].end(), c) != trees[i].end()) {
			return i;
		}
	}
	return -1; // In case it doesn't belong to any
}

int main() {
	// Read number of test cases
	scanf("%d\n", &n);

	while (n>0) {
		v.clear();
		e.clear();
		trees.clear();

		// Read edges
		while (scanf(" ( %c , %c )\n", &c1, &c2)) {
			e.push_back(make_pair(c1, c2));
		}

		// Discard line of ****
		scanf("%*s\n");

		// Read vertices
		scanf(" %c", &c1);
		v.push_back(c1);
		while (scanf(",%c", &c1)) {
			v.push_back(c1);
		}
		scanf("\n");

		// Analysing each edge we build the trees
		int tree1, tree2;
		for (int i = 0; i < e.size(); ++i) {
			tree1 = belongs_to(e[i].first);
			tree2 = belongs_to(e[i].second);
			if (tree1 < 0 && tree2 < 0) {
				// In case both vertices don't belong to any tree,
				// we create a new tree and add them both.
				vc new_tree;
				new_tree.push_back(e[i].first);
				new_tree.push_back(e[i].second);
				trees.push_back(new_tree);
			} else if (tree2 < 0) {
				// One of the vertice belongs to a tree, but the other
				// doesn't, so we add it to the other one's tree
				trees[tree1].push_back(e[i].second);
			} else if (tree1 < 0) {
				// One of the vertice belongs to a tree, but the other
				// doesn't, so we add it to the other one's tree
				trees[tree2].push_back(e[i].first);
			} else if (tree1 == tree2) {
				// Both vertices belong to the same tree already
				continue;
			} else {
				// Boths vertices belong to different trees,
				// so join the trees
				trees[tree1].insert(trees[tree1].end(),
					trees[tree2].begin(), trees[tree2].end());
				trees[tree2][0] = '#'; // Mark the tree as invalid
			}
		}

		// Count how many trees are there
		nt = 0;
		for (int i = 0; i < trees.size(); ++i) {
			if (trees[i][0] != '#') nt += 1;
		}

		// Count number of acorns
		na = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (belongs_to(v[i]) < 0) na += 1;
		}

		printf("There are %d tree(s) and %d acorn(s).\n", nt, na);

		n -= 1; // Next test case
	}

	return 0;
}
