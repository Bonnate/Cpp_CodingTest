#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    stack<int> s;
    vector<char> ans;
    int next = 1;        // 다음에 push할 수
    for (int i = 0; i < n; ++i) {
        int ref = v[i];

        // ref까지 push
        while (next <= ref) {
            s.push(next++);
            ans.push_back('+');
        }

        // top 검사 (매 loop 당 1번 pop을 해야 함)
        if (s.empty() || s.top() != ref) {
            cout << "NO\n";
            return 0;
        }

        s.pop();
        ans.push_back('-');
    }

    for (char c : ans) cout << c << '\n';
    return 0;
}