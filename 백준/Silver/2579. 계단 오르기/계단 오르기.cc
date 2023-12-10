#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(301, -1);
int input[301];

int func(int n)
{
	// 0보다 작다면 0리턴
	if (n < 0)
		return 0;

	int& ret = dp[n];

	// 해당 값이 이미 있다면, 즉시 리턴
	if (ret != -1)
		return ret;

	ret = max(ret, func(n - 2) + input[n]);
	ret = max(ret, func(n - 3) + input[n - 1] + input[n]);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> input[i];

	cout << func(N);
}