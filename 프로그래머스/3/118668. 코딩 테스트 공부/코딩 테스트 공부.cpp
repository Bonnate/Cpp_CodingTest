#include <string>
#include <vector>
#include <algorithm>
#define MAX_VALUE 1000000

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    // dp의 인덱스 번호는 현재 알고력과 코딩력의 누적 cost
    vector<vector<int>> dp(152, vector<int>(152, MAX_VALUE));
    
    // 요구하는 코딩력과 알고력을 구하기
    int maxAlp = alp, maxCop = cop;
    for(vector<int>& problem : problems)
    {
        maxAlp = max(maxAlp, problem[0]);
        maxCop = max(maxCop, problem[1]);
    }
    
    // 만약 alp와 cop가 요구하는 값 이상이라면 0 리턴
    if(alp >= maxAlp && cop >= maxCop)
        return 0;
    
    dp[alp][cop] = 0; // 시작 부분은 0
    for(int i = alp; i <= maxAlp; ++i)
    {
        for(int j = cop; j <= maxCop; ++j)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1); // 알고리즘 공부
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1); // 코딩 공부
            
            // 모든 문제를 검사
            for(vector<int>& problem : problems)
            {
                // 문제를 풀기위한 최소 알고력, 코딩력이 있다면?
                if(i >= problem[0] && j >= problem[1])
                {
                    // 기존 점수와 문제에서 얻은 점수의 합이 maxAlp, maxCop을 넘지 못하게 방지
                    // maxAlp + 1, 2..도 어차피 같은 경우로, [maxAlp][maxCop]에 값을 쓰고, 인덱스 번호를 추가로 사용하지 않도록 최적화
                    int alpIdx = min(maxAlp, problem[2] + i);
                    int copIdx = min(maxCop, problem[3] + j);
                    
                    // 문제를 풀었을 때, cost를 비교하여 낮은 값으로 갱신
                    dp[alpIdx][copIdx] = min(dp[alpIdx][copIdx], dp[i][j] + problem[4]);
                }
            }
        }
    }
    
    // 정답 리턴
    return dp[maxAlp][maxCop];
}