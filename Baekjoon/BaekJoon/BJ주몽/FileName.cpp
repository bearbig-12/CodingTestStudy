#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int count = 0;
	int target;
	int answer = 0;

	cin >> count;
	cin >> target;

	vector<int> v(count, 0);


	for (int i = 0; i < count; ++i)
	{
		int num;
		cin >> num;
		v[i] = num;
	}

	sort(v.begin(), v.end());


	int start = 0;
	int end = count - 1;


	while (start < end)
	{
		if (v[start] + v[end] > target)
		{
			end--;
		}
		else if (v[start] + v[end] < target)
		{
			start++;
		}
		else if (v[start] + v[end] == target)
		{
			start++;
			end--;
			answer++;
		}
	}

	cout << answer;



}