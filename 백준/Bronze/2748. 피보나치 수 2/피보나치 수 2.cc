#include <iostream>
using namespace std;

int main()
{
	long long dp[91];

	dp[0] = 0;
	dp[1] = 1;

	int N;
	cin >> N;

	for (int i = 2; i <= N; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[N] << endl;
}