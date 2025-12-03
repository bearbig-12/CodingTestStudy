#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 이 문제에서의 핵심은 "안입음"이라는 선택지 이다.
// 아무것도 안입는 선택은 불가하지만, 
// headgear → 2개 아이템 + “안 입음” = 3가지 선택
// eyewear → 1개 아이템 + “안 입음” = 2가지 선택
// 이렇게 존재하고 경우의 수는 3 x 2이다. 여기서 위에서 언급한 아무 것도 안입음 이라는 값을 빼주면 된다.

int solution(vector<vector<string>> clothes) {

    int answer = 1;
    unordered_map<string, vector<string>> hash;

    for (int i = 0; i < clothes.size(); ++i)
    {
        hash[clothes[i][1]].push_back(clothes[i][0]);
    }

    for (auto s : hash)
    {
        answer *= s.second.size();
    }
    return answer - 1;
}


int main()
{
    vector<vector<string>> clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    vector<vector<string>> clothes2 = { { "crow_mask", "face" }, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } };
    cout << solution(clothes2);


};

