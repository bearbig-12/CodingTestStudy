#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int DP[15][15]{0};

	for (int i = 0; i < 15; ++i)
	{
		DP[0][i] = i;
	}

	int test;
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		//Ãþ
		int k;
		int n;



		cin >> k >> n;
		
		for (int j = 1; j <= k; ++j)
		{
			for (int s = 1; s <= n; ++s)
			{

				// Á¡È­½Ä = aÃþÀÇ bÈ£´Â aÃþ b-1È£ + a-1Ãþ b-1È£
				DP[j][s] = DP[j - 1][s] + DP[j][s - 1];
			}
		}


		cout << DP[k][n] << '\n';



	}
}