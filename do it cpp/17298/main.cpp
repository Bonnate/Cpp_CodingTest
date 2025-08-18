#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    static int arr[1000000];
    static int result[1000000];
    stack<int> s;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }

    for (int i = 0; i < N; ++i) {
        const int current = arr[i];

        while (!s.empty() && current > arr[s.top()]) {
            result[s.top()] = current;
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()) {
        result[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; ++i) {
        cout<<result[i]<<" ";
    }

    return 0;
}