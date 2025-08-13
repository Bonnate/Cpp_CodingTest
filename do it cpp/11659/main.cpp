#include <iostream>

int main() {
    int n, m;
    int num[100001];
    int sum[100001];
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) {
        scanf("%d",&num[i]);
        sum[i] = num[i] + sum[i-1];
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", sum[r] - sum[l-1]);
    }

    return 0;
}