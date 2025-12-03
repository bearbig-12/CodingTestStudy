#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;


    for (int i = 0; i < arr.size() - 1; ++i)
    {
        if (arr[i] != arr[i + 1])
        {
            answer.push_back(arr[i]);
        }

    }
    answer.push_back(arr[arr.size() - 1]);

    



    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}


int main()
{
    vector<int> v = { 1,1,3,3,0,1,1 };
    vector<int> v2 = { 4,4,4,3,3 };


    solution(v2);
}