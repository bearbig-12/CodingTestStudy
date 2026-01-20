#include <iostream>
#include <stack>
#include <vector>
#include <string>

// 백준 2023번 신기한 소수

using namespace std;


// 소수 2 3 5 7
vector<char> table{ '2','3','5','7' };
vector<int> table_int{ 2,3,5,7 };

vector<bool> visitied(1000001, false);

int N;

bool isPrime(int num)
{
	if (num <= 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	for (int i = 3; i * 1LL * i <= num; i += 2)
		if (num % i == 0) return false;

	return true;
}

//void DFS(char c)
//{
//	vector<char> nextDigits = { '1','3','7','9' };
//	string s;
//	s += c;
//
//	stack<string>st;
//	st.push(s);
//	while (!st.empty())
//	{
//		string curr = st.top();
//	
//		st.pop();
//
//		if (!isPrime(stoi(curr)))
//		{
//			continue;
//		}
//
//		if (curr.size() == N)
//		{
//			cout << curr << '\n';
//			continue;
//		}
//
//		for (int i = nextDigits.size() - 1; i >= 0 ; --i)
//		{
//			string next = curr + nextDigits[i];
//			st.push(next);
//		}
//	}
//}

void DFS_Recursive(int num, int jarisu)
{
	if (!isPrime(num))
	{
		return;
	}

	if (jarisu == N)
	{

		cout << num << '\n';
		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		int newNum = num * 10 + i;
		if (isPrime(newNum))
		{
			DFS_Recursive(newNum, jarisu + 1);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < table.size(); ++i)
	{
		//DFS(table[i]);
		DFS_Recursive(table_int[i], 1);
	}

}