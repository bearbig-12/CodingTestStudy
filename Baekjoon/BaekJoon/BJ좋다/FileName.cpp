#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1253

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N;
	cin >> N;

	vector<int> v(N, 0);

	int answer = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}


	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i)
	{
		int start = 0;
		int end = N - 1;
		int find = v[i];

		while (start < end)
		{
			if (v[start] + v[end] == find)
			{
				if (start != i && end != i)
				{
					answer++;
					break;
				}
				// 자기자신은 피하고
				else if(start == i)
				{
					start++;
				}
				else if (end == i)
				{
					end--;
				}
				
			}
			else if (v[start] + v[end] < find)
			{
				start++;
			}
			else if (v[start] + v[end] > find)
			{
				end--;
			}

		}
	}
	cout << answer;
}
