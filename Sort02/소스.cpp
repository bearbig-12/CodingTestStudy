#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//합친 문자 비교해서 큰순으로 정렬하기, ex ) 6, 10 이 있다면 610과 106하고 어떤게 큰지 비교
// 610이 더크므로 6, 10순으로 정렬하게 된다.
// 반대로 가장 작을 수를 구하려면  a + b < b + a 하면 된다.
bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> temp;
    for (auto a : numbers)
    {
        temp.push_back(to_string(a));
    }

    sort(temp.begin(), temp.end(), cmp);

    if (stoi(temp[0]) == 0)
    {
        return "0";
    }

    for (int i = 0; i < temp.size(); ++i)
    {
        answer += temp[i];
    }

    return answer;
}


int main()
{
    vector<int> v = { 6,10,2 };

    string temp = solution(v);
    cout << temp;


}