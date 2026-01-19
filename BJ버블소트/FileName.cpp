#include <iostream>
#include <vector>
#include <algorithm>


// 백준 1377 버블 소트 골드 2
// 안쪽 For 문이 얼마나 돌았는지를 찾는 문제이다. 
// 키포인트는 정렬전 Index와 정렬 후 Index를 비교 후 최대 값을 찾는 문제
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	vector<pair<int, int>> v(N, {0,0});

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		v[i].first = num;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		if (max < v[i].second - i)
		{
			max = v[i].second - i;
		}
	}

	cout << max + 1;

}