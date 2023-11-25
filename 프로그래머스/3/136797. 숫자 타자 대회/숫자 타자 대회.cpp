#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<char, pair<int, int>> m;
int dp[100001][10][10];

int getWeight(int from, char c) {
    int x = abs(m[c].first - m[from + '0'].first) ;
    int y = abs(m[c].second - m[from + '0'].second);
    
    int weight = -1;
    if(!x && !y)
        return 1;
    else if(!x || !y)
        return max(x, y) * 2;
    else
    {
        int minValue = min(x, y);
        x -= minValue;
        y -= minValue;
        return minValue * 3 + max(x, y) * 2;
    }
}

int func(string& numbers, int left, int right, int idx)
{
    if(idx == numbers.size())
        return 0;
    
    if(left == right)
    {
        // cout<<"같음!"<<endl;
        return 99999999;
    }
    
    if(dp[idx][left][right])
        return dp[idx][left][right];
    
    int leftW1 = getWeight(left, numbers[idx]);
    int rightW1 = getWeight(right, numbers[idx]);
    
    int leftW2 = leftW1 + func(numbers, numbers[idx] - '0', right, idx + 1);
    int rightW2 = rightW1 + func(numbers, left, numbers[idx] - '0', idx + 1);
    
    // cout<<numbers[idx]<<" "<<leftW2<<" "<<rightW2<<endl;
    
    return dp[idx][left][right] = min(leftW2, rightW2);
}

int solution(string numbers) {
    char c = '1';
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            m[c++] = {i, j};
    m['0'] = {3, 1};
  
    return func(numbers, 4, 6, 0);
}