#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {

    // 오름차순 정렬
    sort(targets.begin(), targets.end());

    int answer = 1;
    for(int i = 0; i < targets.size(); ++i)
    {
        // 최대 요격 e좌표
        int last = targets[i][1];

        for(; i < targets.size(); ++i)
        {
            // 다음 위치의 s좌표가 last 이상이라면 함께 요격 불가능
            if(targets[i][0] >= last)
            {
                ++answer, --i;
                break;
            }

            // 최대 요격 좌표는 점점 줄어들을 수 있음
            last = min(last, targets[i][1]);
        }
    }

    return answer;
}