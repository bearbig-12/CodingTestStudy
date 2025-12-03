#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    int cnt = 1;
    while (1)
    {
        pair<int, int> temp = q.front();

        if (pq.top() != temp.first)
        {
            q.pop();   
            q.push(temp);
        }
        else
        {
            if (temp.second == location)
            {
                answer = cnt;
                return answer;
            }
            else
            {
                cnt++;
                q.pop();
                pq.pop();
            }
            
        }

      

    }
}


int main()
{
    vector<int> v = { 6,2,1,5,4,5 };
    cout << solution(v,2);
}