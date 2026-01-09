#include <iostream>
#include <vector>
// 백준 문제 번호 10986 골드3

//문제
//	수 N개 A1, A2, ..., AN이 주어진다.이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
//	즉, Ai + ... + Aj(i ≤ j) 의 합이 M으로 나누어 떨어지는(i, j) 쌍의 개수를 구해야 한다.

// 핵심 아이디어 
// S[j] % M 의 값과 S[i] % M 의 값이 같다면 (S[j] - S[i]) % M 의 값은 0이다. 즉 구간의 합 배열의 원소를 M으로 나눈 나머지로 바꾸고
//  S[i], S[j]가 같은 쌍 { i,j }을 찾으면 원본 배열에서 i+1 부터 j 까지의 구간의 합이 M으로 나누어 떨어지는 것을 알 수 있다.

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_count;
	int M;


	cin >> num_count >> M;

	vector<long> S(num_count, 0);
	vector<long> C(M, 0);
	long answer = 0;
	cin >> S[0];

	for (int i = 1; i < num_count; ++i)
	{
		int num = 0;
		cin >> num;
		S[i] = S[i - 1] + num;
	}

	for (int i = 0; i < num_count; ++i)
	{
		int remainder = S[i] % M;
		// 0~i 까지 구간의 합이 0인 경우
		if (remainder == 0)
		{
			answer++;
		}
		// 나머지가 같은 인덱스의 갯수
		C[remainder]++;
	}


	for (int i = 0; i < M; ++i)
	{
		if (C[i] > 1)
		{
			// 나머지가 같은 인덱스 중에서 2개를 뽑는 경우의 수 aC2
			answer += C[i] * (C[i] - 1) / 2;
		}
	}

	cout << answer;

}