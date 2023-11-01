#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	int d = n - 1, p = n - 1;

	while (d >= 0 && deliveries[d] == 0)
		--d;

	while (p >= 0 && pickups[p] == 0)
		--p;

	long long answer = 0;
	while (d >= 0 || p >= 0)
	{
		int deliver = cap;
		int pickup = cap;

		int target = max(d, p);

		while (d >= 0 && deliver > 0)
		{
			int land = min(deliver, deliveries[d]);
			deliveries[d] -= land;
			deliver -= land;

			while (d >= 0 && deliveries[d] == 0)
				--d;
		}

		while (p >= 0 && pickup > 0)
		{
			int pick = min(pickup, pickups[p]);
			pickups[p] -= pick;
			pickup -= pick;

			while (p >= 0 && pickups[p] == 0)
				--p;
		}

		answer += ((target + 1) * 2);
	}

	return answer;
}