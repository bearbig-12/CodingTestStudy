#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// h번 이상 인용된 논문이 h편 이상이고, 나머지 논문이 h번 이하일때 h의 최댓값 찾기
// 예를 들어, 10 9 6 6 5 4 일때, 
// 10은 10번이상 인용된 논문이 10개가 있어야 된다. -> 불가
// 9도 위와 같은 이유로 불가(2개)
// 6도 4개 불가
// 5는 가능 5개
// 4도 가능 6개

// 즉 여기서 가장 큰 숫자는 5
bool cmp(int& a, int& b)
{
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;

    // 최대값을 찾는 문제이니 내림차순으로 정렬
    sort(citations.begin(), citations.end(), cmp);


    for (int i = 0; i < citations.size(); ++i)
    {
        // i + 1은 논문 갯수
        if (citations[i] >= i + 1)
            answer = i + 1;
        else
            break;
    }


    return answer;
}


int main()
{
    vector<int> v = { 3,0,6,1,5 };

    cout << solution(v);
}