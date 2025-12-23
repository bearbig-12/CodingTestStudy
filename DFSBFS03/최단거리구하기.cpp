#include<vector>
#include <queue>
#include <utility>   // pair
#include <iostream>  // (테스트 출력용, 없어도 되지만 추천)
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0 , 0 ,-1, 1 };

int BFS(vector<vector<int>>& maps)
{
	queue<pair<int, int>> q;
	int row = maps.size();
	int col = maps[0].size();

	vector<vector<int>> visited(row, vector<int>(col, -1));

	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();


		int currY = curr.first;
		int currX = curr.second;

		for (int i = 0; i < 4; ++i)
		{
			int nX = currX + dx[i];
			int nY = currY + dy[i];

			if ((nX >= 0 && nY >= 0) &&  (nX < col && nY < row) && (maps[nY][nX] != 0) && visited[nY][nX] == -1)
			{
				q.push({ nY,nX });

				visited[nY][nX] = visited[currY][currX] + 1;
			}

		}


	}
	return visited[row - 1][col - 1];

}

int solution(vector<vector<int>> maps)
{
	int answer = 0;
	answer = BFS(maps);
	return answer;
}
int main()
{
	vector<vector<int>> maps = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1 } };
	solution(maps);
}