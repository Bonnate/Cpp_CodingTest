#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    queue<int> q;

    cin>>N;

    if (N == 1) {
        cout<<1<<endl;
        return 0;
    }

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    while (true) {
        q.pop();
        if (q.size() == 1) {
            cout<<q.front()<<endl;
            return 0;
        }
        int front = q.front();
        q.pop();
        q.push(front);
    }
}