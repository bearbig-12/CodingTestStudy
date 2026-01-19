#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string s; 
	cin >> s;

	int lengh = s.length();

	vector<int> v(lengh, 0);

	for (int i = 0; i < s.length(); ++i)
	{
		v[i] = (int)(s[i]);
	}
	sort(v.begin(), v.end(), comp);
	string t;

	for (int i = 0; i < v.size(); ++i)
	{
		t += (char)(v[i]);
	}


	cout << stoi(t);
}