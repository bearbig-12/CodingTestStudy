#include <iostream>
#include <vector>



using namespace std;





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int day;

    vector<pair<int, int>> table;
    cin >> day;

    int DP[20]{0};

    for (int i = 1; i <= day; ++i)
    {
        int time;
        int money;
        cin >> time >> money;
        table.push_back({ time, money });
    }


    for (int i = 1; i <= day; ++i)
    {
        // 일을 한다고 했을때 그 일이 끝나는 날짜
        int end = i + table[i-1].first;
        if (end <= day + 1 )
        {
            DP[end] = max(DP[end], DP[i] + table[i-1].second);
        }

        DP[i + 1] = max(DP[i], DP[i + 1]);
    }
    cout << DP[day+1] << endl;
}
    
