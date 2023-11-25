#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<char, pair<int, int>> m;
int dp[100001][10][10];

int getWeight(int from, char c) {
    // from을 기준으로 c에 해당하는 x, y의 길이를 가져오기
    int x = abs(m[c].first - m[from + '0'].first) ;
    int y = abs(m[c].second - m[from + '0'].second);
    
    int weight = -1;
    if(!x && !y) // 만약 x, y가 from과 같은 위치라면 1 리턴
        return 1;
    else if(!x || !y) // 만약 x나 y중 하나가 0이라면, 직선 거리만 사용하기에 큰 값 * 2 리턴
        return max(x, y) * 2;
    else // 대각선이 포함된경우 직선거리 * 2 + 대각선거리 * 3 리턴
    {
        int minValue = min(x, y);
        x -= minValue;
        y -= minValue;
        return minValue * 3 + max(x, y) * 2;
    }
}

int func(string& numbers, int left = 4, int right = 6, int idx = 0)
{
    // 끝까지 검사하였다면 리턴
    if(idx == numbers.size())
        return 0;

    // 두 손가락의 위치가 같으면 안되기에 매우 큰 수를 리턴하여 사용할 수 없도록 함
    if(left == right)
        return 99999999;
    
    // 이미 해당 값이 있다면, 중복 연산을 피하기 위하여 즉시 리턴
    if(dp[idx][left][right])
        return dp[idx][left][right];
    
    // 현재 left와 right의 위치에서 numbers[idx]까지의 가중치를 구하기
    int leftW1 = getWeight(left, numbers[idx]);
    int rightW1 = getWeight(right, numbers[idx]);
    
    // left와 right를 이용한 가중치를 각각 구하기
    int leftW2 = leftW1 + func(numbers, numbers[idx] - '0', right, idx + 1);
    int rightW2 = rightW1 + func(numbers, left, numbers[idx] - '0', idx + 1);

    // 각 가중치에서 최소값을 선택
    return dp[idx][left][right] = min(leftW2, rightW2);
}

int solution(string numbers) {
    // 숫자 글자에 해당하는 위치를 map에 저장
    char c = '1';
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            m[c++] = {i, j};
    m['0'] = {3, 1};
  
    // 정답 구하기
    return func(numbers);
}