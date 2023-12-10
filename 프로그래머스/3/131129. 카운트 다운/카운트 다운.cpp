#include <string>
#include <vector>

using namespace std;

int dp[100001][2];

void check(int target) {
    // target - 60의 누적 개수와 target - 50의 누적 개수가 같다면?
    if (dp[target - 60][0] == dp[target - 50][0]) 
    {
        dp[target][0] = dp[target - 50][0] + 1; // 누적 개수 1 증가
        dp[target][1] = max(dp[target - 60][1], dp[target - 50][1] + 1); // max(target - 60의 값, target - 50의 값 + 1(불 사용))
    }
    // target - 60이 더 효율적이라면?
    else if (dp[target - 60][0] < dp[target - 50][0]) 
    {
        dp[target][0] = dp[target - 60][0] + 1;
        dp[target][1] = dp[target - 60][1];
    }
    else 
    {
        dp[target][0] = dp[target - 50][0] + 1;
        dp[target][1] = dp[target - 50][1] + 1;
    }
}

vector<int> solution(int target) {
    vector<int> answer(2, 0);

    for (int i = 1; i <= target; i++) {
        /* 한 번에 끝내기 */
        // 싱글(20이하) 또는 불(50)로 끝내는 경우
        if (i == 50 || i <= 20) 
        {
            dp[i][0] = 1;
            dp[i][1] = 1; // 값 증가
        }
        // 60 이하의 3의 배수인 경우는 트리플로 가능
        else if (i <= 60 && i % 3 == 0) 
        {
            dp[i][0] = 1;
            dp[i][1] = 0; // 싱글,불이 아님
        }
        // 40 이하의 2의 배수인 경우에는 더블로 가능
        else if (i <= 40 && i % 2 == 0) 
        {
            dp[i][0] = 1;
            dp[i][1] = 0; // 싱글, 불이 아님
        }
        /* 블+싱글 조합으로 두 번에 끝내기 */
        // 50보다 크고 70 이하라면 2번(불 + 싱글)로 가능
        else if (i > 50 && i <= 70) 
        {
            dp[i][0] = 2;
            dp[i][1] = 2; // 불 + 싱글의 조합으로 2 증가
        }
        /* 나머지 두 번에 끝내기 */
        // 70보다 작은 수인경우, 아래의 두 조건으로 나눌 수 있음
        else if (i < 70) 
        {
            // 40 보다 작은 수라면, 싱글 2개로 조합 가능
            if (i < 40) 
            {
                dp[i][0] = 2;
                dp[i][1] = 2; // 싱글 2개
            }
            // 아니라면, 싱글 + 더블 조합으로 가능
            else 
            {
                dp[i][0] = 2;
                dp[i][1] = 1; // 싱글 1개
            }
        }
        // 71부터는 저장된 값을 고려하여 최선의 선택을 구하기
        else 
        {
            check(i);
        }
    }

    answer[0] = dp[target][0];
    answer[1] = dp[target][1];

    return answer;
}