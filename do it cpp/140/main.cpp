#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    sort(numbers.begin(), numbers.end());

    int left = 0, right = N - 1;
    int answer = 0;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == M) {
            ++answer;
            ++left;
            --right;
        }
        else if (sum > M) {
            --right;
        }
        else if (sum < M) {
            ++left;
        }
        else {
        }
    }

    printf("%d", answer);

    return 0;
}