#include <string>
#include <vector>
using namespace std;

vector<int> arr(11);
vector<int> answer{ -1 };
int maxScore = -1;

void DFS(int l, int n, vector<int> info) {
	if (l == 11)
	{
		int score = 0;
		for (int i = 0; i < 10; ++i)
		{
			if (info[i] < arr[i])
				score += (10 - i);
			else if (info[i])
				score -= (10 - i);
		}

		// 점수가 같을때, 더 낮은 점수를 맞추면 갱신
		if (maxScore <= score && score > 0)
		{
			if (maxScore != score)
			{
				answer = arr;
				maxScore = score;
			}
			else
			{
				for (int i = info.size() - 1; i >= 0; --i)
				{
					if (arr[i] != answer[i])
						if (answer[i] > arr[i])
							return;
						else
							break;
				}

				answer = arr;
			}
		}
	}
	else
	{
		for (int i = n; i >= 0; --i)
		{
			arr[l] = i;
			DFS(l + 1, n - arr[l], info);

			if (l == 10)
				break;
		}
	}
}

vector<int> solution(int n, vector<int> info) {
	DFS(0, n, info);

	return answer;
}