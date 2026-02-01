#include <iostream>
#include <algorithm>

using namespace std;

// 백준 1300번


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T;
	cin >> N >> T;


	int start = 1;
	int end = T;
	int ans = 0;

	while (start <= end)
	{
		int middle = (start + end) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; ++i)
		{
			cnt += min(middle / i, N);
		}

		if (cnt < T)
		{
			start = middle + 1;
		}
		else if (cnt >= T) 
		{
			ans = middle;      // 일단 가능
			end = middle - 1;   // 더 작은 값 있나?
		}

	}

	cout << ans;
}