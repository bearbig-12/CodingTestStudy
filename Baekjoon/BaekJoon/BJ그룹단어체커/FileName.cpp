#include <iostream>
#include <vector>	
#include <set>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int test_case;

	cin >> test_case;

	int answer = 0;

	string s;

	set<char> set;

	for (int i = 0; i < test_case; ++i)
	{
		cin >> s;
		set.clear();
		bool checker = true;
		for (int j = 0; j < s.length(); ++j)
		{
			if (j < s.length() - 1)
			{
				if (s[j] == s[j + 1])
				{
					continue;
				}
			}
		
			if (set.find(s[j]) == set.end())
			{
				set.insert(s[j]);
			}
			else
			{
				checker = false;
				break;
			}
		}

		if (checker)
		{
			answer++;
		}

	}
	
	cout << answer;

}	