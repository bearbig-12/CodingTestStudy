#include <iostream>

using namespace std;

int main()
{
	int DP[15][15] = { 0 };
	int n;
	cin >> n;

	// 0층
	for (int i = 1; i <= 14; ++i)
	{
		DP[0][i] = i;
	}

	// 1호는 항상 1명
	for (int i = 0; i <= 14; ++i)
	{
		DP[i][1] = 1;
	}

	for (int i = 1; i <= 14; ++i)
	{
		for (int j = 2; j <= 14; ++j)
		{
			DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
		}
	}

	while (n--) {
		int k, n;
		cin >> k >> n;
		cout << DP[k][n] << "\n";
	}

}