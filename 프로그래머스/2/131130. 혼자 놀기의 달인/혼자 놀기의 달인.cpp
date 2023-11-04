#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> arr;

// Find
int Find(int n)
{
    if (n == arr[n]) return n;
    else return arr[n] = Find(arr[n]);
}

// Union
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        arr[a] = b;
}

int solution(vector<int> cards) {
    
    arr = vector<int>(cards.size() + 1);
    
    // 집합 정보 초기화
    for (int i = 1; i <= cards.size(); ++i)
        arr[i] = i;
    
    for(int i = 0; i < cards.size(); ++i)
    {
        Union(i + 1, cards[i]);
    }
    
    for(int i = 1; i <= cards.size(); ++i)
        Find(i);
    
    map<int, int> m;
    for(int i = 1; i <= cards.size(); ++i)
        ++m[arr[i]];
    
    priority_queue<int> q;
    for(pair<int, int> p : m)
        q.push(p.second);
    
    if(q.size() == 1)
        return 0;
    
    int answer = 1;
    for(int i = 0; i < 2; ++i)
    {
        answer *= q.top();
        q.pop();
    }
    
    return answer;
}