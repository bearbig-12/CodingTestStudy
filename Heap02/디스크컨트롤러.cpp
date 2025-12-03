#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct comp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
         return a.second > b.second;    
    }
};


int solution(vector<vector<int>> jobs) {

    sort(jobs.begin(), jobs.end());  // 기본 정렬로 요청시간 기준 정렬

    int time = 0;
    int returntime = 0;
    int end = jobs.size();
    int ended = 0;
    int answer = 0;
    priority_queue <pair<int,int>, vector<pair<int,int>>, comp> pQ;

    while (true)
    {
        if (end == ended && pQ.empty())
        {
            answer = returntime;
            break;
        }
 
   

        while (ended < end && time >= jobs[ended][0])
        {
            // {요청 시간 , 소요 시간}
            pQ.push({ jobs[ended][0], jobs[ended][1] });
            ended++;
        }
      

        if (!pQ.empty())
        {
            returntime += time + pQ.top().second - pQ.top().first;
            time += pQ.top().second;
            pQ.pop();
        }
        else
        {
            time++;
        }
    }

    
    return answer / jobs.size();
}

int main()
{
    vector<vector<int>> v = { {0, 3 }, { 1, 9 }, { 3, 5 } };

    solution(v);
};