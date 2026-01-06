#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	int answer = 0;

	vector<string> alpha = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	int idx = 0;
	int count = 0;
	bool isFound = false;

	while (true)
	{
		for (int i = 0; i < alpha.size(); ++i)
		{
			count = 0;
			if (input[idx] == alpha[i][0])
			{
				if (idx + alpha[i].length() > input.length())
				{
					continue;
				}
				for (int j = 0; j < alpha[i].length(); ++j)
				{
					
					if (input[idx + j] == alpha[i][j])
					{
						count++;
					}
				}

			}
			if (count == alpha[i].length())
			{
				answer++;
				idx += alpha[i].length();
				count = 0;
				isFound = true;
				break;
			}
			
		}
		if (isFound == false)
		{
			answer++;
			idx++;
		}
		isFound = false;


		if (idx >= input.length())
		{
			break;
		}
	}
	cout << answer;
};

	

	



