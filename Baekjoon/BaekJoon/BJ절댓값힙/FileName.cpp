#include <iostream>
#include <queue>

//น้มุ 11286

using namespace std;
struct comp
{
	bool operator()(const int a, const int b)
	{
		int abs_A = abs(a);
		int abs_B = abs(b);

		if (abs_A == abs_B)
		{
			return a > b;
		}
		else
		{
			return abs_A > abs_B;
		}

	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, comp> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int new_int;
		cin >> new_int;
		if (new_int != 0)
		{
			pq.push(new_int);
		}
		else
		{
			if (pq.size() == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}

	}
}