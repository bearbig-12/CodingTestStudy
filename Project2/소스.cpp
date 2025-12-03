#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = (int)progresses.size();
    int idx = 0;              

    while (idx < n) {
        for (int i = idx; i < n; ++i) {
            if (progresses[i] < 100) {
                progresses[i] += speeds[i];
            }
        }

        int s = 0;
        while (idx < n && progresses[idx] >= 100) {
            ++s;
            ++idx;
        }

        if (s > 0) {
            answer.push_back(s);
        }
    }

    return answer;
}

int main() 
{
    vector<int> v1 = { 93, 30, 55 };
    vector<int> s1 = { 1, 30, 5 };
    auto ans = solution(v1, s1);
    for (auto x : ans) cout << x << ' ';  // ±â´ë: 2 1
}