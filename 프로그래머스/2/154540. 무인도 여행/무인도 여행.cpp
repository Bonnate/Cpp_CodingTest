#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int width, height, sum;

vector<vector<bool>> visit;
vector<int> answer;

// DFS
void DFS(vector<string> maps, int food, int y, int x)
{
	sum += food;

	for (int i = 0; i < 4; ++i)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (xx == -1 || yy == -1 || xx == width || yy == height || maps[yy][xx] == 'X' || visit[yy][xx])
			continue;

		visit[yy][xx] = true;

		DFS(maps, maps[yy][xx] - '0', yy, xx);
	}
}

vector<int> solution(vector<string> maps) {
	height = maps.size();
	width = maps[0].size();

	queue<pair<int, int>> q;
	visit = vector<vector<bool>>(height, vector<bool>(width, false));

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (!visit[i][j] && maps[i][j] != 'X')
			{
				sum = 0;
				visit[i][j] = true;
				DFS(maps, maps[i][j] - '0', i, j);
				answer.push_back(sum);
			}

	sort(answer.begin(), answer.end());
	if (answer.empty())
		answer.push_back(-1);
	return answer;
}