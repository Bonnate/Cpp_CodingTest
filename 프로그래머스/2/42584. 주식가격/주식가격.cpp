#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> s;
    
    // 모든 값 검사
    for(int i = 0; i < n; ++i)
    {
        // s가 비어있지 않을때, 
        // top의 가격이 prices[i]보다 크다면 가격이 떨어지기 시작
        while(!s.empty() && prices[s.top()] > prices[i])
        {
            // answer[s.top()]에는 현재 위치(i) 에서 삽입한 위치(s.top)의 차이를 삽입
            answer[s.top()] = i - s.top();
            s.pop();
        }
        
        // 현재 위치 삽입
        s.push(i);
    }

    // 해당 위치의 가격은 마지막까지 한번도 떨어지지 않은 경우임
    // s가 빌때까지 모두 정답에 삽입
    while(!s.empty())
    {
        answer[s.top()] = n - s.top() - 1;
        s.pop();
    }
    
    return answer;
}