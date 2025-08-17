#include <iostream>

int main() {
    int N;
    scanf("%d", &N);

    int left = 1, right = 1;
    int sum = 1;
    int answer = 1;

    while (right != N) {
        if (sum > N) {
            sum -= left++;
        }
        else if (sum < N) {
            sum += ++right;
        }
        else {
            ++answer;
            sum -= left++;
        }
    }

    printf("%d", answer);
    return 0;
}