#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <math.h>

using namespace std;

// 이 문제의 키 포인트는 순열이다. 순열은 원소의 조합이 같더라도 순서가 다르면 다른 방법이다.
// 예로들어 "011"를 인풋으로 해서 순열을 만들면 {0,1,1} , {1,0,1}, {1,1,0} 이런 경우 숫자로 변환하면 중복되는 경우가 많다.예) 11
// 이런 중복을 없애기 위해서 사용되는 것이 Set << 2번째로 중요한 Key포인트

// 오늘 배운 것은 순열(next_permutation << 이 친구 쓰려면 무죄건 미리 오름차순으로 정렬)
// 그리고 중복되는 것을 막기 위해서는 Set이 굉장히 도움이 된다.

// 소수찾는 법도 잘 기억

bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(number); ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;

}

int solution(string numbers) {
    int answer = 0;
    string s;

    set<int> ans{};

    // next_permutation을 위한 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    do
    {
        string temp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            temp += numbers[i];
            if (isPrime(stoi(temp)))
            {
                ans.insert(stoi(temp));
            }
        }


    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = ans.size();

    return answer;
}

int main()
{
    string s = "011";

    cout << solution(s);
}