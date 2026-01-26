#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

void DFS(int n)
{
	cout << n << " ";
	visited[n] = true;

	for (auto i : graph[n])
	{
		if (visited[i] == false)
		{
			DFS(i);
		}
	}
}

void BFS(int n)
{
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";

		for (auto next : graph[curr])
		{
			if (visited[next] == false)
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Node;
	int Edge;
	int Start;

	cin >> Node >> Edge >> Start;

	graph.resize(Node+ 1);

	visited = vector<bool>(Node+1, false);

	for (int i = 0; i < Edge; ++i)
	{
		int from;
		int to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= Node; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(Start);
	cout << '\n';
	fill(visited.begin(), visited.end(), false);
	BFS(Start);
	cout << '\n';





}