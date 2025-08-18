#include <iostream>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (abs(a.first) == abs(b.first))
            return a.second > b.second;
        return abs(a.first) > abs(b.first);
    }
};

// struct Compare2 {
//     bool operator()(const pair<int, int> a, const pair<int, int> b) const {
//         if (abs(a.first) == abs(b.first))
//             return a.second < b.second;
//         else
//             return abs(a.first) < abs(b.first);
//     }
// };

int main() {
    int N, input;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input;

        if (input == 0) {
            if (pq.empty()) {
                cout<<0<<endl;
            }
            else {
                cout<<pq.top().second<<endl;
                pq.pop();
            }
        }
        else {
            pq.push(pair<int, int>(input, input));
        }
    }

    return 0;
}