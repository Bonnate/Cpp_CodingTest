#include <string>
#include <vector>

using namespace std;

int sel[8];
bool use[8];
int originalStamina;
int answer = -1;

void DFS(int l, int s, vector<vector<int>> dungeons)
{
	if (l == dungeons.size())
	{
		int stamina = originalStamina;
		int cnt = 0;

		for (int i = 0; i < dungeons.size(); ++i)
			if (dungeons[sel[i]][0] <= stamina)
				stamina -= dungeons[sel[i]][1], ++cnt;

		if (cnt > 0)
			answer = max(answer, cnt);
	}
	else
		for (int i = 0; i < dungeons.size(); ++i)
			if (!use[i])
			{
				use[i] = true;
				sel[l] = i;
				DFS(l + 1, i + 1, dungeons);
				use[i] = false;
			}
}

int solution(int k, vector<vector<int>> dungeons) {
	originalStamina = k;
	DFS(0, 0, dungeons);
	return answer;
}