#include<iostream>
#include<stack>
#include<vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<char> result;
	stack<int> s;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	
	}


	int num = 1;

	for (int i = 0; i < N; ++i)
	{

		if (A[i] >= num)
		{
			while (A[i] >= num)
			{
				s.push(num);
				num++;
				result.push_back('+');
			}
		
		}
		if (s.top() == A[i])
		{
			s.pop();
			result.push_back('-');

		}
		else if (s.top() > A[i])
		{
			cout << "NO";
			return 0;
		}	
	}

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << '\n';
	}

}

