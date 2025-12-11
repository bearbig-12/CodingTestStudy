#include <iostream>

using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num_Count;
	int sum_Count;

	cin >> num_Count >> sum_Count;

	int Sum[100001] = {};

	for (int i = 1; i <= num_Count; ++i)
	{
		int number;
		cin >> number;
		Sum[i] = Sum[i - 1] + number; // 합배열 공식
	}

	for (int i = 0; i < sum_Count; ++i)
	{
		int start;
		int end;
		int answer;

		cin >> start >> end;


		answer = Sum[end] - Sum[start - 1];

		cout << answer << '\n';

	}
	


}