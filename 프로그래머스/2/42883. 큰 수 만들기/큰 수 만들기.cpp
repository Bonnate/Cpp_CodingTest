#include <string>
#include <vector>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";
 
    int startIdx = 0;
    // number에서 k개를 뺀 것을 뽑기 위해 number.size() - k 만큼 반복
    for(int i = 0; i < number.size() - k; ++i)
    {
        char maxChar = number[startIdx];
        int maxIdx = startIdx;

        // 시작 위치로부터 k + 1번까지 반복 (뒤에서 뽑을 것을 보장하기 위해 반복을 제한)
        // 만약, 현재 뽑은 값이 마지막 인덱스가 가장 크다면, 다음에 뽑는 경우는 호출되지 않을 수 있음
        // 12345 중 k가 2인경우, {1, 2, [3]}, [4], [5] 가 뽑힘
        for(int j = startIdx; j <= k + i; ++j)
        {
            // 현재 선택에서 최상의 값을 구하기
            if(maxChar < number[j])
            {
                maxChar = number[j];
                maxIdx = j;
            }
        }
        
        // 정답에 추가하고, 다음 반복문은 maxIdx + 1번부터 뽑기 시작
        answer.push_back(maxChar);
        startIdx = maxIdx + 1;
    }
 
    return answer;
}