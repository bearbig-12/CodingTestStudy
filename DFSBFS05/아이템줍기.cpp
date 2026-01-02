#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map(102, vector<int>(102, 0));
int visited[102][102];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };



int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

	// 사각형 사이즈 2배로 늘리고 맵에 표시
	for (int i = 0; i < rectangle.size(); i++) {
        rectangle[i][0] *= 2;
        rectangle[i][1] *= 2;
        rectangle[i][2] *= 2;
        rectangle[i][3] *= 2;

        for (int x = rectangle[i][0]; x <= rectangle[i][2]; ++x)
        {
			for (int y = rectangle[i][1]; y <= rectangle[i][3]; ++y)
            {
				map[y][x] = 1;
            }
        }
    }

	// 테두리만 남기기
    for (int i = 0; i < rectangle.size(); i++) {

        for (int x = rectangle[i][0] + 1; x <= rectangle[i][2] - 1; ++x)
        {
            for (int y = rectangle[i][1] + 1; y <= rectangle[i][3] - 1; ++y)
            {
                map[y][x] = 0;
            }
        }
    }

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

	queue<pair<int, int>> q;   
	q.push({ characterY, characterX });
	visited[characterY][characterX] = 1;

    while (!q.empty())
    {
		auto curr = q.front();
		q.pop();

        int currY = curr.first;
		int currX = curr.second;

        if(currY == itemY && currX == itemX)
        {
            answer = (visited[currY][currX]- 1) / 2;
            break;
        }
        for (int dir = 0; dir < 4; dir++)
        {
			int nY = currY + dy[dir];
			int nX = currX + dx[dir];

            if (nY < 0 || nY >= 102 || nX < 0 || nX >= 102 || visited[nY][nX] != 0)
                continue;
            if (map[nY][nX] == 1)
            {
				visited[nY][nX] = visited[currY][currX] + 1;
				q.push({ nY, nX });
            }

		}

    }


    return answer;
}