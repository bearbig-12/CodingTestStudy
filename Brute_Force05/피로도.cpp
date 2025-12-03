#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int max = 0;
    
    sort(dungeons.begin(), dungeons.end());

    do 
    {
        int total = k;
        answer = 0;

        for (int i = 0; i < dungeons.size(); ++i)
        {
            if (total >= dungeons[i][0])
            {
                total -= dungeons[i][1];
                answer++;
            }
        }
        if (max < answer)
        {
            max = answer;
        }


    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return max;
}


int main()
{
    vector<vector<int>> v = { {80,20}, {50,40}, {30,10} };

    int answer = solution(80, v);
    cout << answer;
}