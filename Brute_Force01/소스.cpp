#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> width;
    vector<int> colum;

    for (int i = 0; i < sizes.size(); ++i)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }

        width.push_back(sizes[i][0]);
        colum.push_back(sizes[i][1]);
    }

 

    int max_width = *max_element(width.begin(), width.end());
    int max_colum = *max_element(colum.begin(), colum.end());

    answer = max_width * max_colum;

    return answer;
}


int main()
{
    vector<vector<int>> v = { {60, 50},{30, 70},{60, 30},{80, 40} };

    cout << solution(v);
}