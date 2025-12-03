#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	priority_queue<int, vector<int>, greater<int>> minHeap;

    int answer = 0;

    for(int s : scoville)
    {
       
        minHeap.push(s);
	}

    if (minHeap.top() >= K)
    {
        return 0;
    }

    while (minHeap.size() > 1 && minHeap.top() < K)
    {
        answer++;

        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int newOne = first + (second * 2);
        
        minHeap.push(newOne);

        
  
    }

    if (minHeap.top() < K)
    {
        return -1;
    }

    return answer;
}

int main()
{
    vector<int> scoville = { 5,1 };
    int K = 7;
    solution(scoville, K);
}

