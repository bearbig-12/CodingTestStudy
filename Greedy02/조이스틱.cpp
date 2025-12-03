#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// A B C D E F G H I J K L M N O P Q R S E U V W S Y Z

// A - > Z 는 25 or 1
// A - > Y 는 24 or 2
int solution(string name) {
    int answer = 0;
    int len = name.length();
    
    // 알파벳을 구하기 위한 조이스틱 조정 횟수( 위, 아래 )
    for (int i = 0; i < len; ++i)
    {
        int a = name[i] - 'A';
        int b = 'Z' - name[i] + 1;

        answer += min(a, b);
    }

    // 순수하게 오른쪽으로만 가기
    int move = len - 1 ;

    // 자리 이동 ( 왼쪽 오른쪽)
    for (int i = 0; i < len; ++i)
    {
       
        int next = i + 1;
        while (next < name.length() && name[next] == 'A')
        {
            next++;
        }

        move = min(move, i * 2 + (len - next));

        move = min(move, i + 2 * (len - next));

    }

    answer += move;

    return answer;
}

int main()
{
    string name = "JAN";


    solution(name);
}