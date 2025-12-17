#include <string>
#include <vector>
#include <stack>
using namespace std;

void dfs(int n, vector<vector<int>> computes, vector<bool>& visited)
{
    stack<int> s;
	s.push(n);
	visited[n] = true;


    while(s.empty() == false)
    {
		int curr = s.top();
        s.pop();
        for (int i = 0; i < computes.size(); ++i)
        {
            if (computes[curr][i] == 1 && visited[i] != true)
            {
                s.push(i);
				visited[i] = true;
            }
        }
	}

}

void dfs(int n, vector<vector<int>> computes, vector<bool>& visited)
{
    visited[n] = true;
    for (int i = 0; i < computes.size(); ++i)
    {
        if (computes[n][i] == 1 && visited[i] == false)
        {
            dfs(i, computes, visited);
		}
    }

}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(201, false);


    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}


int main()
{
        int n = 3;
    vector<vector<int>> computers = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int result = solution(n, computers);
    return 0;

}