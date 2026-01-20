#include <iostream>
#include <stack>
#include <vector>


using namespace std;

static vector<vector<int>> v;
static vector<bool> visited;

//void DFS(int n)
//{
//	stack<int> s;
//	s.push(n);
//	visited[n] = true;
//
//	while (!s.empty())
//	{
//		int curr = s.top();
//		s.pop();
//
//
//		for (int i = 0; i < v[curr].size(); ++i)
//		{
//			if (visited[v[curr][i]] == false)
//			{
//				s.push(v[curr][i]);
//				visited[v[curr][i]] = true;
//			}
//		}
//	}
//}

void DFS_Recursive(int n)
{
	if (visited[n] == true)
	{
		return;
	}

	visited[n] = true;

	for (int i = 0; i < v[n].size(); ++i)
	{
		if (visited[v[n][i]] == false)
		DFS_Recursive(v[n][i]);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int E;

	cin >> N >> E;

	v.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < E; ++i)
	{
		int from;
		int to;

		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);

	}

	int count = 0;
	for (int i = 1; i < N + 1; ++i)
	{
		if (visited[i] == false)
		{
			count++;
			//DFS(i);
			DFS_Recursive(i);
		}
	}


	cout << count;
}