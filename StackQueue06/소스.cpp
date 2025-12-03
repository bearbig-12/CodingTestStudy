#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st; // 인덱스를 저장할 스택

    for (int i = 0; i < prices.size(); ++i)
    {
        while (!st.empty() && prices[st.top()] > prices[i] )
        {
            int topIdx = st.top();
            answer[topIdx] = i - topIdx;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }

    return answer;
}


int main()
{
    vector<int> v = { 1,2,3,2,3 };

    vector<int> a = solution(v);

    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
}