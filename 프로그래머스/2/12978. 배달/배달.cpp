#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 간선 정보
struct Edge2 {
	int to, weight;
};

int solution(int N, vector<vector<int>> road, int K) {
	vector<vector<Edge2>> graph(N + 1);
	vector<int> dist(N + 1, INT_MAX);

	// 그래프 정보 초기화 (양방향)
	for (vector<int> r : road) {
		int from = r[0];
		int to = r[1];
		int weight = r[2];
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	// 우선순위 큐를 이용한 다익스트라 알고리즘
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[1] = 0; // 시작 노드의 거리는 0
	pq.push({ 0, 1 }); // {거리, 노드} 쌍을 우선순위 큐에 삽입

	while (!pq.empty()) {
		int current_distance = pq.top().first;
		int current_node = pq.top().second;
		pq.pop();

		// printf("현재위치: %d, 누적비용: %d\n", current_node, current_distance);

		// 현재 노드에서 갈 수 있는 모든 노드들에 대해 최단 거리 갱신
		for (Edge2& e : graph[current_node])
		{
			int next_node = e.to;
			int weight = e.weight;

			// printf("다음 노드: %d, 비용: %d\n", next_node, weight);

			if (dist[next_node] > current_distance + weight)
			{
				dist[next_node] = current_distance + weight;
				pq.push({ dist[next_node], next_node });

				// printf("노드 갱신: %d, 비용: %d\n", next_node, dist[next_node]);
			}
		}
	}

	// 정답 구하기
	int answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] <= K)
			++answer;

		cout << dist[i] << " ";
	}


	return answer;
}