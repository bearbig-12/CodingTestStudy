#include<string>
#include <iostream>
#include <queue>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> q;
    if (s[0] != '(')
    {
        answer = false;
        return answer;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        
        q.push(s[i]);
    }

    int idx = 1;
    char first = q.front();
    q.pop();
    while (!(q.empty()) )
    {
        char current = q.front();
      
        if (first == current)
        {
            idx++;
        }
        else
        {
            idx--;
        }


        if (idx < 0)
        {
            answer = false;
            return answer;
        }
        q.pop();

        
    }
    
    if (idx > 0)
    {
        answer = false;
    }
    else
    {
        answer = true;
    }


    return answer;


}


int main()
{
    string s = { "(()("};

    cout << solution(s);
}