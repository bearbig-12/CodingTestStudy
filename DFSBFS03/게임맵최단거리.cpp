#include<vector>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 }; 
int dx[4] = { 0,0,-1,1 };   

int BFS(vector<vector<int>>& graph )
{
    int cnt = 0;

	int row = graph.size();
	int col = graph[0].size();

	vector<vector<int> > visited(row, vector<int>(col, -1));

    queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

    while (!q.empty())
    {
		int x = q.front().first;
		int y = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; ++i)
        {
			int nx = x + dx[i];
			int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx == row || ny == col || graph[nx][ny] == 0 || visited[nx][ny] != -1)
            {
                continue;
            }

			q.push({ nx,ny });
			visited[nx][ny] = visited[x][y] + 1;
            
        }
    }
	return visited[row-1][col-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = BFS(maps);
    return answer;
}