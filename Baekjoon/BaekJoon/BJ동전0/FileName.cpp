#include <iostream>
#include <vector>

using namespace std;

// น้มุ 11047

int main()
{
	int C, M;

	cin >> C >> M;

	vector<int> v(C, 0);

	int count = 0;

	for (int i = 0; i < C; ++i)
	{
		cin >> v[i];
	}

	for (int i = C - 1; i >= 0; --i)
	{
		if (v[i] <= M)
		{
			count += M / v[i];
			M = M % v[i];
		}
	}
	cout << count;
}