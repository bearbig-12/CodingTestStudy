#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int dy1[4] = { 1,0,-1,0 };

int dx1[4] = { 0,1,0,-1 };

void DFS(vector<vector<int>>& table, int target)
{
    stack<pair<int, int>> s;
    s.push({ 0,0 });
    int val = table.size() * table.size();
    table[0][0] = val;

    int cycle = 0;

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();
        int curX = curr.second;
        int curY = curr.first;
        if (table[curY][curX] == 1)
        {
            break;
        }
     

        int nY;
        int nX;
        if (cycle == 0)
        {
            nY = curY + dy[1];
            nX = curX;
        

        }
        else if (cycle == 1)
        {
            nY = curY;
            nX = curX + dx[3];
       

        }
        else if (cycle == 2)
        {
            nY = curY + dy[0];
            nX = curX;
            

        }
        else
        {
            nY = curY;
            nX = curX + dx[2];
    
        }
      

        if (nX < 0 || nY < 0 || nX >= table.size() || nY >= table.size() || table[nY][nX] != 0)
        {
            cycle++;
            if (cycle > 3)
            {
                cycle = 0;
            }
            s.push({ curY, curX });
            continue;
        }
        s.push({ nY, nX });
        table[nY][nX] = --val;
     
        

    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    int target;
    cin >> target;

    int val = num * num;

   

    vector<vector<int>> table(num, vector<int>(num));

    //DFS(table, target);
    int curY = 0;
    int curX = 0;
  
    int cycle = 0;

    while (true)
    {   
        table[curY][curX] = val;

        if (table[curY][curX] == 1)
        {
            break;
        }

        val--;

        int dir = cycle % 4;

        int nY = curY + dy1[dir];
        int nX = curX + dx1[dir];

        if (nY >= num || nX >= num || nX < 0 || nY < 0 || table[nY][nX] != 0)
        {
            cycle++;
            dir = cycle % 4;
            nY = curY + dy1[dir];
            nX = curX + dx1[dir];
        }

        curX = nX;
        curY = nY;


    }

    int x = 0;
    int y = 0;

    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table.size(); ++j)
        {
            cout << table[i][j] << " ";
            if (table[i][j] == target)
            {
                y = i + 1;
                x = j + 1;
            }
        }
        cout << '\n';
    }
    cout << y << " " << x;

}