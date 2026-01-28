#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<vector<int>> A(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));


int N;
int M;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void BFS(int n, int m)
{
	queue<pair<int, int>> q;
	q.push({ n,m });
	visited[n][m] = true;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int new_x = curr.first + dx[i];
			int new_y = curr.second + dy[i];

			if ((new_x >= 0) && (new_y >= 0) && new_x < N && new_y < M)
			{
				if (A[new_x][new_y] != 0 && visited[new_x][new_y] == false)
				{
					visited[new_x][new_y] = true;
					q.push({ new_x, new_y });
					A[new_x][new_y] = A[curr.first][curr.second] + 1;
				}
			}

		}


	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j)
		{
			A[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);

	cout << A[N - 1][M - 1];

}