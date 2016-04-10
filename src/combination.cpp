#include <cstdio>
#include <cstdlib>


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d\n", &a, &b, &c, &d);
    // printf("a b c d => %d %d %d %d\n", a, b, c, d);
    while (a || b || c || d) {
        int tot = 720;
        int d1 = (a > b) ? (a - b) : 40 - (b - a);
        tot += d1 * 9;
        tot += 360;
        int d2 = (c > b) ? (c - b) : 40 - (b - c);
        tot += d2 * 9;
        int d3 = (c > d) ? (c - d) : 40 - (d - a);
        tot += d3 * 9;
        // printf("d1 d2 d3 => %d %d %d\n", d1*9, d2*9, d3*9);
        printf("%d\n", tot);
        scanf("%d %d %d %d\n", &a, &b, &c, &d);
        // printf("a b c d => %d %d %d %d\n", a, b, c, d);        
    }
    return 0;
}
