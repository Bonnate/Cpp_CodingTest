#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {

    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
    for(vector<int>& v : road)
    {
        graph[v[0]].push_back({v[1], v[2]});
        graph[v[1]].push_back({v[0], v[2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, INT_MAX);
    
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty())
    {
        int currentDistance = pq.top().first; // 현재 노드까지의 누적 가중치
        int currentNode = pq.top().second; // 현재 노드 위치
        
        pq.pop();
        
        // 현재 노드를 기준으로 갈 수 있는 모든 경로를 반복
        for(pair<int, int>& p : graph[currentNode])
        {
            int nextNode = p.first; // 다음 노드의 번호
            int weight = p.second; // 다음 노드로 가기까지 가중치
        
            // 현재 노드까지의 가중치 + 다음 노드 가중치가 저장된 값보다 더 작다면?
            if(dist[nextNode] > currentDistance + weight)
            {
                dist[nextNode] = currentDistance + weight; // 값을 갱신
                pq.push({dist[nextNode], nextNode}); // 큐에 가중치와 다음노드 번호를 삽입
            }
        }
    }
    
    // 정답 구하기
    int answer = 0;
    for (int i = 1; i <= N; ++i)
        if (dist[i] <= K)
            ++answer;
    
    return answer;
}