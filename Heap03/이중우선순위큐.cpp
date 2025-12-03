#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct comp
{
    bool operator() (const int& a, const int& b)
    {
        return a > b;
    }
};

vector<int> solution(vector<string> operations) { 
    vector<int> answer = { 0,0 };

    priority_queue<int> pQ;
    priority_queue<int, vector<int>, comp> minPQ;
    unordered_map <int, int> hash;

    int max, min = 0;

    int cnt = 0;

    for (int i = 0; i < operations.size(); ++i)
    {
        string first;
        int second;

        first = operations[i].substr(0, operations[i].find(" "));
        second = stoi(operations[i].substr(operations[i].find(" ") + 1, operations[i].length()));


        if (first == "I")
        {
            pQ.push(second);
            minPQ.push(second);
            hash[second]++;            

            cnt++;
        }
        else if(cnt > 0)
        {

            if (second == 1)
            {
                int top = pQ.top();
                hash[top]--;

                pQ.pop();
                cnt--;
            }
         
            else 
            {
                int top = minPQ.top();
                hash[top]--;
                
                minPQ.pop();
                cnt--;
            }
        }
    }

    vector<int> temp;
    if (cnt > 0)
    {
        for (auto n : hash)
        {
            if (n.second > 0)
            {
                temp.push_back(n.first);
            }
        }

        max = *max_element(temp.begin(), temp.end());
        min = *min_element(temp.begin(), temp.end());

        answer[0] = max;
        answer[1] = min;
    }





    return answer;
}



int main()
{
    vector<string> v = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };

    

    solution(v);
}