#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int n = truck_weights.size();
    
    vector<int> v(bridge_length + 1, 0);
    int sum = 0;
    int idx = 0;
    
    while(idx < n)
    {
        // 왼쪽으로 한칸씩 이동
        rotate(v.rbegin(), v.rbegin() + 1, v.rend());
        
		// 마지막에 있는 트럭을 내보내기
		sum -= v[bridge_length]; // 마지막에 있는 트럭의 무게를 빼기
		v[bridge_length] = 0; // 해당 값은 0으로 설정        
        
		// 트랙 보내기 시도
		if (sum + truck_weights[idx] <= weight)
		{
			v[0] = truck_weights[idx++];
			sum += v[0];
		}

		++answer;
    }
    
    for(int i = 0; i < bridge_length; ++i)
        if(v[i])
        {
            answer += bridge_length - i;
            break;
        }
    
    return answer;
}