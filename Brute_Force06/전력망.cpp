#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> graph[101];
vector<bool> visited(101, false);


int Dfs(int node, vector<int> graph[], vector<bool>& visited, int CutA, int CutB)
{

	int cnt = 0;

	stack<int> s;


	s.push(node);
	visited[node] = true;

	while (!s.empty())
	{
		int curr = s.top();
		s.pop();
		cnt++;

		for (int next : graph[curr])
		{
			if (next == CutA && curr == CutB || next == CutB && curr == CutA)
			{
				continue;
			}
			if (!visited[next])
			{
				s.push(next);
				visited[next] = true;

			}
		}
	}

	return cnt;
}

int solution(int n, vector<vector<int>> wires) 
{
	int answer = n;


	for (int i = 0; i < wires.size(); ++i)
	{
		graph[wires[i][0]].push_back(wires[i][1]);
		graph[wires[i][1]].push_back(wires[i][0]);
	}

	for (int i = 0; i < wires.size(); ++i)
	{
		int CutA = wires[i][0];
		int CutB = wires[i][1];

		fill(visited.begin(), visited.end(), false);


		int cnt = Dfs(1, graph, visited, CutA, CutB);

		int diff = abs(cnt - (n - cnt));

		if (answer > diff)
		{
			answer = diff;
		}
	}
	return answer;
}


int main()
{
	vector<vector<int>> wires = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
	cout << solution(9,wires) << "\n";
	return 0;
}