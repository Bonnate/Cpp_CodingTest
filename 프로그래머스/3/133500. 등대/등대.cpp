#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
bool light[100001] = {false, }; // 불이 켜진 등대인지 체크
int answer = 0;

// from: 어느 노드에서 왔는가?
// here: 현재 노드
void DFS(int from, int here) 
{
    // here(현재 위치)에서 갈 수 있는 모든 노드를 검사
    for (int i = 0; i < v[here].size(); i++) 
    {
        // 이전 노드(from)로 돌아가지 않아야 함
        // DFS를 통해 무방향 탐색을 할경우 1 -> 2 -> 3 -> 2처럼 v[here][i] == from이 되는 경우가 있음
        if (v[here][i] != from) 
        {
            // 현재 위치에서 v[here][i]로 이동
            DFS(here, v[here][i]);
            
            // 만약 현재 위치와, 다음 위치 모두 불이 꺼져있는경우, 불을 켜면서, ++answer
            if (!light[v[here][i]] && !light[here]) 
            {
                light[here] = true;
                ++answer;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    v = vector<vector<int>>(n + 1, vector<int>());
    
    // 무방향 그래프로 양쪽으로 이동할 수 있게 삽입
    for(vector<int> path : lighthouse)
    {
        v[path[0]].push_back(path[1]);
        v[path[1]].push_back(path[0]);
    }
    
    // 가상위치(0)에서 1번 노드로 이동하는것으로 탐색 시작
    DFS(0, 1);
    
    return answer;
}