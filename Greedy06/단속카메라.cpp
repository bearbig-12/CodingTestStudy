#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp (const vector<int> & a, const vector<int>& b)
{
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
	sort(routes.begin(), routes.end(), comp);

    int cam = -30001;

    for (auto r : routes)
    {
        if (cam < r[0])
        {
            cam = r[1];
			answer++;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> routes = { {-20,-15}, {-14,-5}, {-18,-13}, {-5,-3} };
    solution(routes);
}