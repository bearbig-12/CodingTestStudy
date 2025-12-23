#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void DFS(vector<vector<int>>& maps, int size)
{
	stack<pair<int, int>> s;


	int row = maps.size();
	int col = maps[0].size();
	int cycle = 0;
	int cnt = 1;
	s.push({ 0,0 });
	maps[0][0] = cnt;

	while (!s.empty())
	{
		auto curr = s.top();
		s.pop();

		int currY = curr.first;
		int currX = curr.second;

		if (maps[currY][currX] == size * size)
		{
			break;
		}
		int nX = currX;
		int nY = currY;
		



		if (cycle == 0)     
		{
			nY = currY;
			nX = currX + dx[3];   
		}
		else if (cycle == 1)   
		{
			nY = currY + dy[1]; 
			nX = currX;
		}
		else if (cycle == 2) 
		{
			nY = currY;
			nX = currX + dx[2];   
		}
		else                  
		{
			nY = currY + dy[0];   
			nX = currX;
		}

		if (nY < 0 || nY >= size || nX < 0 || nX >= size || maps[nY][nX] != 0) 
		{
			cycle++;
			if (cycle == 4)
			{
				cycle = 0;
			}
			s.push({ currY,currX });
			continue;
		}
		s.push({ nY, nX });
		cnt++;
		maps[nY][nX] = cnt;

	}


}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int size;
		cin >> size;

		vector<vector<int>> maps(size, vector<int>(size, 0));
		DFS(maps, size);

		cout << "#" << test_case << "\n";

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				cout << maps[i][j] << " ";
			}
			cout << "\n";
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}