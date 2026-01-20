#include <iostream>
#include <algorithm>
#include <vector>

// น้มุ 11399

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;


	vector<int> v(N,0);
	vector<int> S(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}


	sort(v.begin(), v.end());

	int temp = 0;
	S[0] = v[0];
	for (int i = 1; i < N; ++i)
	{
		S[i] = S[i - 1] + v[i];
	}

	
	for (int i = 0; i < N; ++i)
	{
		temp += S[i];
	}
	cout << temp;
}