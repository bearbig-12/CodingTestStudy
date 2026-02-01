#include <iostream>
#include <queue>


using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		pq.push(num);
	}

	int sum = 0;

	while ((pq.size() > 1))
	{
		if (pq.size() > 1)
		{
			int first = pq.top();
			pq.pop();
			int second = pq.top();
			pq.pop();

			sum += first + second;

			pq.push(first + second);
		}
	}
	cout << sum;
}