#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

using Comparison = bool (*)(int& a, int& b);

bool a(int& a, int& b)
{
    return a < b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
  
    vector<int> temp;


    for (int i = 0; i < commands.size(); ++i)
    {
        
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; ++j)
        {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end(), a);
        answer.push_back(temp[commands[i][2] - 1]);
        temp.clear();
    }

    return answer;
}

int main()
{
    vector <int> arr = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };

    vector<int> answer = solution(arr, commands);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i];
    }

}


