#include <cstdio>
#include <cstdlib>

int max(int N, int speeds[]);

int main() {
    // Read the number of test cases
    int total_tc;
    scanf("%d\n", &total_tc);
    // printf("total_tc => %d\n", total_tc);

    // For each test case
    for (int tc_number = 1; tc_number <= total_tc; ++tc_number) {
        int N;
        scanf("%d", &N);
        // printf("%d", N);
        int speeds[N];

        // Read scary creatures speeds
        for (int i = 0; i < N; ++i) {
            int speed;
            scanf(" %d", &speed);
            // printf(" %d", speed);
            speeds[i] = speed;
        }

        // Calculate minimum speed for the clown
        int clown_speed = max(N, speeds);
        printf("Case %d: %d\n", tc_number, clown_speed);
    }
    return 0;
}

int max(int N, int speeds[]) {
    int temp = 0;
    for (int i = 0; i < N; ++i) {
        if (speeds[i] > temp)
            temp = speeds[i];
    }
    return temp;
}
