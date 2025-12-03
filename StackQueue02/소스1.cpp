#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    /* for (int i = 0; i < progresses.size(); ++i)
     {
         q.push(progresses[i]);
     }*/
    int s = 0;
    while (1)
    {

        for (int i = 0; i < progresses.size(); ++i)
        {
            progresses[i] += speeds[i];
        }
        if (progresses[0] >= 100 && progresses[0] != 0)
        {
            progresses[0] = 0;
            s++;

        }
        for (int i = 1; i < progresses.size() - 1; ++i)
        {
            if (progresses[i - 1] == 0 && progresses[i] >= 100)
            {
                progresses[i] = 0;
                s++;
            }
        }

        answer.push_back(s);


        if (progresses[progresses.size() - 1] == 0)
        {
            break;
        }

    }



    return answer;
}

int main()
{
    vector<int> v1 = { 93,30,55 };
    vector<int> s1 = { 1,30, 5 };

    solution(v1, s1);
}