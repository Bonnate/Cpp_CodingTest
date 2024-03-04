#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

vector<int> numbers { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int sel[10] { 0, };
int N = 0, M = 0;
int answer = INT_MAX;

void dfs(int s, int length)
{
    if(s == length)
    {
        int num = 0;
        
        for(int i = 0; i < length; ++i)
            num += (pow(10, length - i - 1) * numbers[sel[i]]);
            
        answer = min(answer, length + abs(N - num));
    }
    else
    {
        for(int i = 0; i < numbers.size(); ++i)
        {
            sel[s] = i;
            dfs(s + 1, length);
        }
    }
}

int main() {
    int input;

    cin >> N >> M;
    
    for(int i = 0; i < M; ++i)
    {
        cin >> input;
        numbers.erase(find(numbers.begin(), numbers.end(), input));
    }
    
    // 모든 버튼이 망가진경우?
    if(M == 10)
    {
        cout << abs(100 - N);
        return 0;
    }
    
    // 모든 버튼이 망가지지 않은경우?
    if(M == 0)
    {
        cout << min((int)to_string(N).size(), abs(100 - N));
        return 0;
    }    

    int length = to_string(N).size();
    int half = N / 2;
    int mid = pow(10, length - 1) / 2;
    
    // 요구 자리 수 - 1
    if(length > 1)
        dfs(0, length - 1);
    
    // 요구 자리 수    
    dfs(0, length);
    
    // 요구 자리 수 + 1
    dfs(0, length + 1);

    cout << min(answer, abs(100 - N));

    return 0;
}