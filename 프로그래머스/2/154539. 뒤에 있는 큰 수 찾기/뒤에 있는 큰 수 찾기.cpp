#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size());

	
	stack<pair<int, int>> s; // 현재 값, 인덱스 번호를 가지는 스택
	for (int i = 0; i < numbers.size(); ++i)
	{
		// 각 숫자마다 while문을 이용하여 반복
		while (!s.empty())
		{
			// 현재 숫자가 s.top의 숫자보다 크다면?
			if (numbers[i] > s.top().first)
			{
				// 가장 가까이에 있는 큰 숫자
				answer[s.top().second] = numbers[i];
				s.pop();
			}
			else
				break;
		}

		s.push({ numbers[i], i });
	}

	// 스택에서 빠지지 않은 값들은 큰 수가 없는 경우
	while (!s.empty())
	{
		// 해당 위치에 -1로 설정
		answer[s.top().second] = -1;
		s.pop();
	}

	return answer;
}