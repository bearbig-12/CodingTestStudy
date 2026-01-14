#include <iostream>
#include <deque>

using namespace std;

// 백준 11003번

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	int L;

	cin >> N >> L;

	// 값 , 인덱스
	deque<pair<int, int>> dq;

	// Deque을 사용한 슬라이딩 윈도우 기법
	// 항상 제일 작은 값을 앞으로 보내서 최소값을 구하는 형태
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		while (!dq.empty() && dq.back().first > num)
		{
			dq.pop_back();
		}
		dq.push_back({ num, i });

		if (dq.front().second <= i - L)
		{
			dq.pop_front();
		}

		cout << dq.front().first << " ";
	}
}