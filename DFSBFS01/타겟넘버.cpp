#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int Dfs(int n, vector<int> numbers, int target)
{
    stack<pair<int, int>> s;
    s.push({0,0});
    int cnt = 0;

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();


        if (curr.first == numbers.size())
        {
            if (curr.second == target)
            {
                cnt++;
            }
            continue;

        }


        s.push({ curr.first + 1, curr.second + numbers[curr.first] });
        s.push({ curr.first + 1, curr.second - numbers[curr.first] });
    }

    return cnt;
}


int cnt = 0;
void DfsRecursive(int idx, int n, vector<int> numbers, int target)
{
    if (idx == numbers.size())
    {
        if (n == target)
        {
            cnt++;
        }
        return;
    }
    int sum1 = n + numbers[idx];
    int sum2 = n - numbers[idx];
    DfsRecursive(idx + 1, sum1, numbers, target);
    DfsRecursive(idx + 1, sum2, numbers, target);

}

int solution(vector<int> numbers, int target) {

    int answer = 0;

    DfsRecursive(0, 0, numbers, target);

    answer = cnt;

    return answer;
}

int main()
{
    vector<int> numbers = { 1,1,1,1,1 };
    cout << solution(numbers, 3);
}