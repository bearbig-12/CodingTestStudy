#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> words = { "A", "E", "I", "O", "U" };
int cnt = 0;
int total = 0;
//void Dfs(string curr, string word)
//{
//    stack<string> st;
//    st.push(curr);
//
//    // 스택은 LIFO 구조이므로, 사전순(A,E,I,O,U)으로 꺼내기 위해
//    // 미리 단어들을 뒤집어서(U,O,I,E,A) 넣는다.
//	reverse(words.begin(), words.end());
//
//    while (!st.empty())
//    {
//        string now = st.top();
//        st.pop();
//
//        if (now != "")
//        {
//            cnt++;
//
//            if (now == word)
//            {
//                total = cnt;
//                return;
//            }
//        }
//
//        if(now.length() >= 5)
//			continue;
//
//
//
//        for (string s : words)
//        {
//			st.push(curr + s);
//        }
//    }
//}

void Dfs(string curr, string word)
{
    if (curr == word)
    {
        total = cnt;
        return;
    }
    
	if (curr.length() >= 5)
        return;

	for (string s : words)
    {
        cnt++;
        Dfs(curr + s, word);
    }
}

int solution(string word) {
    int answer = 0;

    Dfs("", word);
    answer = total;
    return answer;

}


int main()
{
	cout << solution("I") << "\n";
    return 0;
}