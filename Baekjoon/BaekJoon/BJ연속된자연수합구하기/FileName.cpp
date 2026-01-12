#include <iostream>

using namespace std;

// 백준 2018번 실버 5
// 투포인터 형식으로 푸는 문제
// 자연수 N의 값이 10,000,000으로 매우크다. 이런 상황에서는 nlogn으로 풀면 시간 초과하므로 O(n)을 사용해야한다. 10 100 1000 10000 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N = 0;
	cin >> N;

	int startIdx = 1;
	int endIdx = 1;
	int sum = 1;
	int count = 0;


	while (endIdx <= N)
	{
		if (sum == N)
		{
			count++;
			endIdx++;
			sum += endIdx;
		}
		else if (sum < N)
		{
			endIdx++;
			sum += endIdx;
		}
		else if (sum > N)
		{
			sum -= startIdx;
			startIdx++;

		}


	}


	cout << count;
}