#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    scanf("%d", &N);

    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numbers[i]);
    }

    std::sort(numbers.begin(), numbers.end());

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        int left = 0;
        int right = N - 1;
        int target = numbers[i];

        while (left < right) {
            if (left == i) {
                ++left;
                continue;
            }
            if (right == i) {
                --right;
                continue;
            }

            int sum = numbers[left] + numbers[right];

            if (sum == target && left != right && left != i && right != i) {
                ++answer;
                break;
            }
            if (sum > target) {
                --right;
            }
            else {
                ++left;
            }
        }
    }

    printf("%d", answer);

    return 0;
}