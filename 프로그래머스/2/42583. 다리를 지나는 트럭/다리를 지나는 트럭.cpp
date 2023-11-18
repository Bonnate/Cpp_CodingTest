#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q;
    int sum = 0;
    int idx = 0;
    int time = 0;
    int n = truck_weights.size();
    
    while(idx < n)
    {
        if(!q.empty() && time >= q.front().second)
        {
            sum -= q.front().first;
            int answer = q.front().second;
            q.pop();
        }
        
        if(sum + truck_weights[idx] <= weight)
        {
            q.push({truck_weights[idx], time + bridge_length});
            sum += truck_weights[idx++];
        }
        
        ++time;
    }
    
    while(q.size() != 1)
        q.pop();
    return q.front().second + 1;
}