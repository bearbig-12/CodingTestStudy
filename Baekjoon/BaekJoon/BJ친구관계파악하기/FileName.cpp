#include <iostream>
#include <vector>


using namespace std;

// น้มุ 13023 ABCDE

vector<vector<int>> A;
vector<bool> visited;
bool arrive = false;

void DFS(int n, int depth)
{
	if (depth == 5)
	{
		arrive = true;
		return;
	}

	if (arrive)
	{
		return;
	}

	visited[n] = true;
	for (int i = 0; i < A[n].size(); ++i)
	{
		if (!visited[A[n][i]])
		{
			DFS(A[n][i], depth + 1);
		}
	}

	visited[n] = false;


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int E;

	cin >> N >> E;

	A.resize(N);
	visited = vector < bool >(N, false);

	for (int i = 0; i < E; ++i)
	{
		int from;
		int to;
		cin >> from >> to;

		A[from].push_back(to);
		A[to].push_back(from);
	}

	for (int i = 0; i < N; ++i)
	{
		if (arrive)
		{
			break;
		}
		DFS(i, 1);
	}

	if (arrive)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

}