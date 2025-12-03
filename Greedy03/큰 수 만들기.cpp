#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int size = number.size();
    string s = "";

    for (int i = 0; i < size; ++i)
    {
        while (!answer.empty() && k > 0 && answer.back() < number[i])
        {
            answer.pop_back();
            --k;
        }
        answer.push_back(number[i]);
    }

    // 아직 k가 남아 있다면 뒤에서 더 지워주기
    while (k > 0) {
        answer.pop_back();
        k--;
    }
    
    return answer;

}

int main()
{
    string i = "1231234";

    solution(i, 3);
      
}