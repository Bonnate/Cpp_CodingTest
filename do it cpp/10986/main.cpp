#include <iostream>
#include <map>

int main() {
    int num[1000001] = {0};
    long long sum[1000001] = {0};
    std::map<int, int> freq;

    int n, m;
    long long answer = 0;;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        sum[i] = sum[i - 1] + num[i];
    }

    for (int i = 1; i <= n; i++) {
        int mod = sum[i] % m;
        freq[mod]++;
    }

    if (freq.count(0)) {
        answer += freq[0];
    }

    for (const std::pair<const int, int>& p : freq) {
        long long cnt = p.second;
        if (cnt > 1) {
            answer += cnt * (cnt - 1) / 2;
        }
    }

    printf("%lld", answer);

    return 0;
}
