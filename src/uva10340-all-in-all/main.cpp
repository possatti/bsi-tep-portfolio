#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main() {
	char s[256];
	char t[256];
	bool subseq = false;

	scanf("%s %s", s, t);
	// printf("==> %s %s\n", s, t);

	while (s[0]!='\0')
	{
		// DEBUG:
		// printf("DEBUG: Working with: %s ; %s\n", s, t);
		// printf("DEBUG: s length: %d\n", strlen(s));
		// printf("DEBUG: t length: %d\n", strlen(t));

		// Check subsequence.
		int i = 0;
		int j = 0;
		bool b = false;
		while (i < strlen(s) && j < strlen(t)) {
			// printf("DEBUG: i=%d, j=%d\n", i, j);
			// printf("DEBUG: s[i]=%c, s[j]=%c\n", s[i], s[j]);
			if (s[i] != t[j]) {
				j++;
			} else {
				i++;
				j++;
			}
			if (i == strlen(s)) {
				b = true;
				// printf("DEBUG: We got a winner!\n");
			}
		}

		// Print result
		if (b) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

		// Read next two strings.
		s[0] = '\0';
		t[0] = '\0';
		scanf("%s %s", s, t);
		// printf("==> %s %s\n", s, t);
	}

	return 0;
}
