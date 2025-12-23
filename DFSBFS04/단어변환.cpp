#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool Check(const string a, const string b)
{
    int diff = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            diff++;
        }
    }

    if (diff == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BFS(string word, vector<string> words, string target, int cnt)
{
    queue<pair<string, int>> q;
    vector < bool> visited(50, false);

    q.push({ word, cnt });

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        if (curr.first == target)
        {
            return curr.second;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            if (Check(curr.first, words[i]) && !visited[i])
            {
                q.push({ words[i], curr.second + 1 });
                visited[i] = true;
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    answer = BFS(begin, words, target, 0);
    return answer;
}

int main()
{

}




