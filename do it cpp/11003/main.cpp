#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    deque<int> dq;
    for (int i = 0; i < N; ++i) {
        while (!dq.empty() && A[dq.back()] > A[i])
            dq.pop_back();

        dq.push_back(i);

        int left = i - L + 1;
        if (dq.front() < left)
            dq.pop_front();

        cout << A[dq.front()] << ' ';
    }
    return 0;
}