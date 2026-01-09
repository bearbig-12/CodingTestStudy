#include <iostream>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_count = 0;
	int test_case = 0;
	
	int DP[100001] = {};

	cin >> num_count >> test_case;

	int answer = 0;

	for (int i = 1; i <= num_count; ++i)
	{
		int num;
		cin >> num;

		DP[i] = DP[i - 1] + num;
	}

	for (int i = 0; i < test_case; ++i)
	{
		int a;
		int b;

		cin >> a >> b;

		answer = DP[b] - DP[a - 1];
		cout << answer << '\n';
	}


}