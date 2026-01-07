#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	vector<string> table;
	int max_length = 0;
	vector<char> temp;

	for (int k = 0; k < 5; ++k)
	{
		getline(cin, s);
		max_length = max(max_length, (int)s.length());
		table.push_back(s);
	}
		

	for (int i = 0; i < max_length; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i > table[j].size()-1)
			{
				continue;
			}
			temp.push_back(table[j][i]);
		}
	}

	for (int i = 0; i < temp.size(); ++i)
	{
		cout << temp[i];
	}

}