#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool isCheckd = false;

bool comp(const vector<string>& a, const vector<string>& b)
{
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
   
}

void DFS(string curr, int used_count, vector<vector<string>>& tickets, vector<bool>& visited)
{
    answer.push_back(curr);
    if (used_count == tickets.size())
    {
        isCheckd = true;
    }

    for (int i = 0; i < tickets.size(); ++i)
    {
        if (visited[i] == false && curr == tickets[i][0])
        {
            visited[i] = true;
            DFS(tickets[i][1], used_count + 1, tickets, visited);
            if (!isCheckd)
            {
                visited[i] = false;
                answer.pop_back();
            }

        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end(), comp);
    vector<bool> visited(tickets.size(), false);


    DFS("ICN", 0, tickets, visited);
     

    
    
   

    return answer;
}


int main()
{
    vector<vector<string>> v = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO" } };
    vector<vector<string>> v1 = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"}};

    solution(v1);
}