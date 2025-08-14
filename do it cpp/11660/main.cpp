#include <iostream>

int main() {
    static int arr[1025][1025];
    static int sum[1025][1025];

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &arr[i][j]);
            sum[i][j] = arr[i][j] + sum[i -1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int result = sum[x2][y2] + sum[x1-1][y1-1] - sum[x2][y1 -1] - sum[x1 -1][y2];
        printf("%d\n", result);
    }

    return 0;
}