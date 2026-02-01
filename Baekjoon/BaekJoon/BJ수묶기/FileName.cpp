#include <iostream>
#include <queue>;


using namespace std;

//백준 1744번
// 큰 수 끼리 묶어야 값이 커진다 단, 여기서 고려 해야할 것은 총 4가지이다.
// 양의 수, 음의 수, 0 과 1
// 양의 수는 큰 수끼리 곱할수록 합이 커집니다.
// 1은 다른 수와 곱해도 의미 없이 그냥 더한다
// 음수끼리는 곱하면 양수가 됩니다. 절대값이 큰 음수(작은 수)끼리 곱해야 큰 양수가 됩니다.
// 0의 역할: 만약 음수가 홀수 개 남았을 때 0이 있다면, 남은 음수와 0을 곱해서 음수를 없애버리는 것이 최선입니다. 0이 없다면 음수는 그냥 더해야 합니다.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int zero = 0;
	int one = 0;

	priority_queue<int> plusPq;
	priority_queue<int, vector<int>, greater<int>> minusPq;

	
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			zero++;
		}
		if (num == 1)
		{
			one++;
		}

		if (num >= 2)
		{
			plusPq.push(num);
		}
		else if (num <= -1)
		{
			minusPq.push(num);
		}
	}

	int sum = 0;

	while (plusPq.size() > 1)
	{
		int first = plusPq.top();
		plusPq.pop();
		int second = plusPq.top();
		plusPq.pop();

		sum += first * second;
	}
	if (plusPq.size() == 1)
	{
		sum += plusPq.top();
		plusPq.pop();
	}


	while (minusPq.size() > 1)
	{
		int first = minusPq.top();
		minusPq.pop();
		int second = minusPq.top();
		minusPq.pop();

		sum += first * second;
	}
	if (minusPq.size() == 1)
	{
		if (zero >= 1)
		{
			sum += 0 * minusPq.top();
			minusPq.pop();
			zero--;
		}
		else if (zero == 0)
		{
			sum += minusPq.top();
			minusPq.pop();
		}
		
	}

	sum += one;

	cout << sum;

}