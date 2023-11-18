#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q;
    int sum = 0; // 현재 다리에 있는 트럭의 무게 합
    int idx = 0; // 삽입할 인덱스 번호
    int time = 0; // 경과된 시간
    int n = truck_weights.size(); // 트럭의 개수
    
    while(idx < n)
    {
        // q가 비어있지 않으면서, q의 front의 시간이 경과되었다면? (도착)
        if(!q.empty() && time >= q.front().second)
        {
            sum -= q.front().first; // 무게에서 빼기
            q.pop(); // 큐에서 제거
        }
        
        // idx번째의 트럭을 다리에 둘 수 있는가? (무게를 초과하지 않는가?)
        if(sum + truck_weights[idx] <= weight)
        {
            q.push({truck_weights[idx], time + bridge_length}); // 큐에 트럭의 무게와 도착 예정 시간 삽입
            sum += truck_weights[idx++]; // 무게 합
        }
        
        ++time; // 시간 경과
    }
    
    // 큐의 가장 마지막 원소의 시간 + 1을 리턴
    return q.back().second + 1;
}