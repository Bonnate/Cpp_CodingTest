#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 간선 정보
struct Edge {
    int from, to, weight;
};

int solution(int N, vector<vector<int>> road, int K) {
    vector<Edge> edges;
    vector<int> dist(N + 1, INT_MAX);

    // 그래프 정보 초기화 (무방향 그래프로 양측 노드에 삽입)
    for (vector<int> r : road) {
        edges.push_back({ r[0], r[1], r[2] });
        edges.push_back({ r[1], r[0], r[2] });
    }

    // 시작 노드의 거리는 0
    dist[1] = 0; 

    // 벨만-포드 알고리즘
    // 모든 노드에 대한 가장 짧은 경로는 노드의 수보다 하나 작은 간선의 수(N-1)로 이루어지기에 N-1번 반복
    for (int i = 0; i < N - 1; ++i)
        for (Edge edge : edges) 
        {
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;
    
            // 아직 다른 간선에 의해 비용이 계산되지 않은경우에는 무시
            if(dist[from] == INT_MAX)
                continue;
            
            // 현재 위치의 비용(dist[from]) + 다음 위치까지의 비용(weight)이 저장된 비용(dist[to])보다 작으면 갱신
            dist[to] = min(dist[to], dist[from] + weight);
        }
    
    // 정답 구하기
    int answer = 0;
    for(int i = 1; i <= N; ++i)
        if(dist[i] <= K)
            ++answer;

    return answer;
}