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
    
    // 각 인덱스에서 가리키는 cards[i]번째 인덱스를 같은 그룹으로 묶기
    for(int i = 0; i < cards.size(); ++i)
        Union(i + 1, cards[i]);
    
    // 동일한 그룹끼리 값을 동일하게 검사
    for(int i = 1; i <= cards.size(); ++i)
        Find(i);
    
    // 그룹의 크기를 구하기 위해 map에 저장
    map<int, int> m;
    for(int i = 1; i <= cards.size(); ++i)
        ++m[arr[i]];
    
    // 우선순위 큐를 이용하여 내림차순 정렬
    priority_queue<int> q;
    for(pair<int, int> p : m)
        q.push(p.second);
    
    // 그룹의 사이즈가 1이라면 0 리턴
    if(q.size() == 1)
        return 0;
    
    // 그룹의 사이즈가 2이상이라면, 2개를 가져와 곱하여 리턴
    int answer = 1;
    for(int i = 0; i < 2; ++i)
    {
        answer *= q.top();
        q.pop();
    }
    
    return answer;
}