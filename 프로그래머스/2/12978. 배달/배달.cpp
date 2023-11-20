#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge
{
    int from, to, weight;
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<Edge> edges;
    for(vector<int> v : road)
    {
        edges.push_back({v[0], v[1], v[2]});
        edges.push_back({v[1], v[0], v[2]});
    }
    
    vector<int> dist(N + 1, INT_MAX);
    dist[1] = 0;
    for(int i = 0; i < N - 1; ++i)
        for(Edge edge : edges)
        {
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;

            if(dist[from] == INT_MAX)
                continue;

            dist[to] = min(dist[to], dist[from] + weight);
        }
    
    for(int i = 1; i <= N; ++i)
    {
        cout<<dist[i]<<endl;
    }
    
    for(int i = 1; i <= N; ++i)
        if(dist[i] <= K)
            ++answer;
    
    return answer;
}