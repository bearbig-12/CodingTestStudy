#include <string>
#include <vector>
#include <stack>

using namespace std;

void DFS(int n, vector<vector<int>> computers, vector<bool>& visited)
{
	stack<int> s;
	s.push(n);
	visited[n] = true;


	while (!s.empty())
	{
		int curr = s.top();
		s.pop();

		for (int i = 0; i < computers.size(); ++i)
		{
			if (computers[curr][i] == 1 && !visited[i])
			{
				s.push(i);
				visited[i] = true;
			}
		}
	}

}


int solution(int n, vector<vector<int>> computers) 
{
	int answer = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			DFS(i, computers, visited);
			answer++;
		}
	}

	return answer;
}


int main()
{

}