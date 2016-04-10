#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define NQUEENS 8

int queens[NQUEENS+1];
int n, row, col;
int soln = 0;

int solve_queens(int c);

int main() {
    scanf("%d\n", &n);
    while (n--) {
        scanf("%d %d\n", &row, &col);

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        soln = 0;
        solve_queens(1);

        if (n) printf("\n");
    }
    return 0;
}

void print_soln(int t);
int is_safe(int r, int c);

int solve_queens(int c) {
    // printf("solve_queens(%d)\n", c);
    if (c > NQUEENS) {
        print_soln(NQUEENS);
    }
    else if (c == col) {
        if (is_safe(row, col)) {
            queens[c] = row;
            solve_queens(c+1);
        }
    }
    else {
        for (int i = 1; i <= NQUEENS; i++) {
            if (is_safe(i,c)) {
                queens[c] = i;
                solve_queens(c+1);
            }
        }
    }
    return 0;
}

int is_safe(int r, int c) {
    int i = 1;
    while (i < c) {
        if (queens[i] == r
            || (i + queens[i]) == (r + c)
            || (i - queens[i]) == (c - r)) return 0;
        i++;
    }
    return 1;
}

void print_soln(int t) {
    soln += 1;
    printf("%2d     ", soln);
    for (int i = 1; i <= t; i++) {
        printf(" %d", queens[i]);
    }
    printf("\n");
}

