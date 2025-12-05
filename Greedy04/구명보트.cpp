#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int right = 0;
    int left = people.size() - 1;

    sort(people.begin(), people.end());

    while (right <= left)
    {
        if (people[right] + people[left] <= limit)
        {
            right++;
            left--;
            answer++;

        }
        else
        {
            left--;
            answer++;

        }

    }

    return answer;
}

int main()
{
    vector<int> s = { 70, 50, 80, 50 };

    solution(s, 100);
}