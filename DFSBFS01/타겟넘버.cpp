#include <string>
#include <vector>
#include <stack>

using namespace std;

int answer = 0;

//int Dfs(int idx, int sum, vector<int> numbers, int target)
//{
//    stack<pair<int, int>> s; 
//
//    s.push({ 0,0 });
//
//    while (!s.empty())
//    {
//        auto top = s.top();
//        s.pop();
//
//        if (idx == numbers.size())
//        {
//            if (sum == target)
//            {
//                answer++;
//            }
//            continue;
//        }
//
//        s.push({ idx + 1, sum + numbers[idx] });
//        s.push({ idx + 1, sum - numbers[idx] });
//    }
//}

void Dfs(int idx, int sum, vector<int> numbers, int target)
{
    if (idx == numbers.size())
    {
        if (sum == target)
        {
            answer++;
        }
        return;
    }


    Dfs(idx + 1, sum + numbers[idx], numbers, target);
    Dfs(idx + 1, sum - numbers[idx], numbers, target);

}

int solution(vector<int> numbers, int target) {

    Dfs(0, 0, numbers, target);


    return answer;
}


int main()
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    solution(numbers, target);
}