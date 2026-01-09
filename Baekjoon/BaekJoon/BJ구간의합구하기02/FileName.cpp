#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// N X N 
	int N = 0;
	int test_cast = 0;

	cin >> N >> test_cast;

	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> DP(N+1, vector<int>(N+1, 0));

	// 겹치는 부분을 잘 생각하자

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int num;
			cin >> num;
			DP[i][j] = DP[i][j - 1] + DP[i - 1][j] + num - DP[i - 1][j - 1];
		}
	}


	for (int i = 0; i < test_cast; ++i)
	{
		int x1;
		int y1;
		int x2;
		int y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int answer = DP[x2][y2] - DP[x1 - 1][y2] - DP[x2][y1 - 1] + DP[x1 - 1][y1 - 1];

		cout << answer << '\n';
	}
	

	return 0;

}