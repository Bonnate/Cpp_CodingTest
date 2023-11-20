#include<vector>
#include<queue>
using namespace std;

int dx[4] { -1, 1, 0, 0};
int dy[4] { 0, 0, -1, 1};
 
int solution(vector<vector<int> > maps)
{
    int row = maps.size();
    int col = maps[0].size();
    
    vector<vector<int>> dist(row, vector<int>(col, -1));
    
    queue<pair<int, int>> q;
       
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for(int i = 0; i < 4; ++i)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(xx == -1 || yy == -1 || xx == col || yy == row || maps[yy][xx] == 0 || dist[yy][xx] != -1)
                continue;
            
            q.push({yy, xx});
            dist[yy][xx] = dist[y][x] + 1;
        }
    }
    
    return dist[row - 1][col - 1];
}