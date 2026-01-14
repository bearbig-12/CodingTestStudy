#include <iostream>
#include <deque>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S;
	int P;

	string s;
	int array[4]{0,0,0,0};
	int check[4]{ 0,0,0,0 };
	cin >> S >> P;
	cin >> s;

	int answer = 0;


	deque<char> dq;

	for (int i = 0; i < P; ++i)
	{
		if (s[i] == 'A')
		{
			array[0]++;
		}
		else if (s[i] == 'C')
		{
			array[1]++;

		}
		else if (s[i] == 'G')
		{
			array[2]++;

		}
		else if (s[i] == 'T')
		{
			array[3]++;

		}

		
	}

	for (int i = 0; i < 4; ++i)
	{
		int n;
		cin >> n;
		check[i] = n;
	}

	if (array[0] >= check[0] && array[1] >= check[1] && array[2] >= check[2] && array[3] >= check[3])
	{
		answer++;
	}

	// 슬라이딩 윈도우 문제
	for (int i = P; i < S; ++i)
	{


		// 끝에 더하고
		if (s[i] == 'A')
		{
			array[0]++;
		}
		else if (s[i] == 'C')
		{
			array[1]++;

		}
		else if (s[i] == 'G')
		{
			array[2]++;

		}
		else if (s[i] == 'T')
		{
			array[3]++;

		}
		int j = i - P;
		// 앞에 뺴고
		if (s[j] == 'A')
		{
			array[0]--;
		}
		else if (s[j] == 'C')
		{
			array[1]--;

		}
		else if (s[j] == 'G')
		{
			array[2]--;

		}
		else if (s[j] == 'T')
		{
			array[3]--;

		}


		if (array[0] >= check[0] && array[1] >= check[1] && array[2] >= check[2] && array[3] >= check[3])
		{
			answer++;
		}
	}

	cout << answer;


}
