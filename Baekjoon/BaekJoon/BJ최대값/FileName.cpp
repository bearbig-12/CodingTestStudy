#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	int max_num = -1;
	int max_row = 0;
	int max_col = 0;

	vector<vector<int>> table(9, (vector<int>(9,0)));

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> num;
			if (num > max_num)
			{
				max_num = num;
				max_row = i + 1;
				max_col = j + 1;
			}
			table[i][j] = num;
			
		}
	}

	cout << max_num << '\n';
	cout << max_row << " " << max_col;
}