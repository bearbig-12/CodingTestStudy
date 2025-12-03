#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<int> all;
    all.assign(n, 1);
    int answer = 0;


    for (int i = 0; i < reserve.size(); ++i)
    {
        all[reserve[i] - 1]++;
    }

    for (int i = 0; i < lost.size(); ++i)
    {
        all[lost[i]-1]--;
    }

   

    for (int i = 0; i < n ; ++i)
    {
        if (all[i] == 0)
        {
            // 앞에 애한테 빌리기
            if (i > 0 && all[i - 1] == 2)
            {
                all[i - 1]--;
                all[i]++;
            }
            // 뒷 친구
            else if (i < n - 1 && all[i + 1] == 2)
            {
                all[i + 1]--;
                all[i]++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (all[i] > 0)
        {
            answer++;
        }
    }

    
    return answer;
}



int main()
{
    solution(3, { 3 }, { 1 });
}