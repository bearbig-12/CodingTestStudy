#include <iostream>
#include <vector>
#include <algorithm>

// น้มุ 1920

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);





	int N, T;

	cin >> N;

	vector<int> v(N, 0);

	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		v[i] = n;
	}

	cin >> T;
	vector<int> a(T, 0);
	for (int i = 0; i < T; ++i)
	{
		int n;
		cin >> n;
		a[i] = n;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < a.size(); ++i)
	{
		bool isIn = false;
		
		int start = 0;
		int end = N - 1;

		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (v[mid] > a[i])
			{
				end = mid - 1;
			}
			else if (v[mid] < a[i])
			{
				start = mid + 1;
			}
			else if( v[mid] == a[i])
			{
				isIn = true;
				break;
			}

		}
		if (isIn)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';

		}
	}

}