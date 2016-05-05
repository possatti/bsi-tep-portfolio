// UVA 10189 - Minesweeper

#include <cstdio>
#include <cstdlib>

char getValue(char field[], int n_lin, int n_col, int l, int c) {
	if (l<0 || l>=n_lin || c<0 || c>=n_col) {
		return '\0';
	}
	return field[l * n_col + c];
}

void setValue(char field[], int n_lin, int n_col, int l, int c, char value) {
	field[l * n_col + c] = value;
}

void print_field(char field[], int n_lin, int n_col) {
	char ch;
	for (int l = 0; l < n_lin; ++l) {
		for (int c = 0; c < n_col; ++c) {
			ch = getValue(field, n_lin, n_col, l, c);
			printf("%c", ch);
		}
		printf("\n");
	}
}

// Count surrouding mines
int count(char field[], int n_lin, int n_col, int l, int c) {
	int n = 0;
	if (getValue(field, n_lin, n_col, l-1, c-1) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l-1, c) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l-1, c+1) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l, c-1) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l, c) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l, c+1) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l+1, c-1) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l+1, c) == '*') n += 1;
	if (getValue(field, n_lin, n_col, l+1, c+1) == '*') n += 1;
	return n;
}

void solve(char field[], int n_lin, int n_col) {
	char ch;
	int n;
	char digit[2]; // The digit + '\0'
	for (int l = 0; l < n_lin; ++l) {
		for (int c = 0; c < n_col; ++c) {
			ch = getValue(field, n_lin, n_col, l, c);
			if (ch == '.') {
				n = count(field, n_lin, n_col, l, c);
				sprintf(digit, "%d", n);
				// printf("%c\n", digit[0]);
				setValue(field, n_lin, n_col, l, c, digit[0]);
			}
		}
	}
}

int main() {
	int tc = 0; // Number of test cases
	int n_lin, n_col;
	scanf("%d %d\n", &n_lin, &n_col);
	// printf("==> %d %d\n", n_lin, n_col);

	while (n_lin != 0) {
		tc += 1;
		char minefield[n_lin * n_col];
		char ch;

		// Read the field
		for (int l = 0; l < n_lin; ++l) {
			for (int c = 0; c < n_col+1; ++c) {
				scanf("%c", &ch);
				if (ch != '\n')
					setValue(minefield, n_lin, n_col, l, c, ch);
			}
		}

		// Solve the field
		solve(minefield, n_lin, n_col);

		// Print solved field
		printf("Field #%d:\n", tc);
		print_field(minefield, n_lin, n_col);

		// Read the next field's size
		scanf("%d %d\n", &n_lin, &n_col);

		// Print an extra new line, if that's not the last field
		if (n_col!=0)
			printf("\n");
	}

	return 0;
}