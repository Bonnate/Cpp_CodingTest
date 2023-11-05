#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int getMin(string format)
{
	return stoi(format.substr(0, 2)) * 60 + stoi(format.substr(3, 2));
}

struct parkInfo
{
	int parkingTime;
	int totalTime;
};

vector<int> solution(vector<int> fees, vector<string> records) {
	map<string, parkInfo> m;

	for (string s : records)
	{
		int min = getMin(s.substr(0, 5));
		bool isIn = s[11] == 'I';
		string carNo = s.substr(6, 4);

		// 이미 값이 있다면?
		if (m.find(carNo) != m.end())
		{
			if (m[carNo].parkingTime != -1)
			{
				m[carNo].totalTime += (min - m[carNo].parkingTime);
				m[carNo].parkingTime = -1;
			}
			else
			{
				m[carNo].parkingTime = min;
			}
		}
		else
		{
			m[carNo].totalTime = -fees[0];
			m[carNo].parkingTime = min;
		}
	}

	vector<int> answer;
	for (pair<string, parkInfo> p : m)
	{
		int cost = fees[1];

		if (p.second.parkingTime != -1)
			p.second.totalTime += (getMin("23:59") - p.second.parkingTime);

		if (p.second.totalTime > 0)
			cost += ceil(p.second.totalTime / (float)fees[2]) * fees[3];

		answer.push_back(cost);
	}

	return answer;
}
