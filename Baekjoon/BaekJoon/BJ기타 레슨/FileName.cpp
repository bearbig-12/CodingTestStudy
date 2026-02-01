#include <iostream>
#include <vector>

using namespace std;



// น้มุ 2343น๘

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int result = 0;

	int C, N;

	cin >> C >> N;

	int start = 0;
	int end = 0;
	v.resize(C);

	for (int i = 0; i < C; ++i)
	{
		cin >> v[i];
		if (start < v[i])
		{
			start = v[i];
		}
		end += v[i];
	}


	while (start <= end)
	{
		int middle = (start + end) / 2;
		int sum = 0;
		int count = 1;
		for (int i = 0; i < C; ++i)
		{
			if (sum + v[i] > middle)
			{
				count++;
				sum = 0;
			}
			sum += v[i];
		
		}

		if (count <= N)
		{
			end = middle - 1;	
			result = middle;
		}
		else
		{
			start = middle + 1;
		}
	}

	cout << result;
}