#include <string>
#include <vector>
#include <queue>

using namespace std;


// 트럭 한대가 다리를 지나는데 걸리는 시간은 다리길이
// 무게 여유가 되어서, 추가로 들어가려면 앞차가 들어가고 1초 후에 진입 
// 무게가 안되면 앞차가 끝까지 갈때까지 대기.


int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<int> remain_cars;
    queue<int> bridge;

    for (int i = 0; i < truck_weights.size(); ++i)
    {
        remain_cars.push(truck_weights[i]);
    }

    int weightSum = 0;

    while (!remain_cars.empty() || weightSum > 0)
    {
        answer++;

        // 다리가 꽉 찼으면(=bridge_length칸이 찼으면) 맨 앞 칸 내보내기
        if ((int)bridge.size() == bridge_length)
        {
            weightSum -= bridge.front();
            bridge.pop();
        }

        // 대기 트럭이 있으면 진입 시도
        if (!remain_cars.empty())
        {
            int next = remain_cars.front();
            if (weightSum + next <= weight)
            {
                bridge.push(next);
                weightSum += next;
                remain_cars.pop();
            }
            else
            {
                // 못 올라가면 빈칸(0)으로 전진만
                bridge.push(0);
            }
        }
        else
        {
            // 대기 트럭은 없고, 다리 위만 남아 있으면 0을 넣어 전진
            if (weightSum > 0) bridge.push(0);
        }
    }

    return answer;
}

int main()
{
    vector<int> v = { 7,4,5,6 };
    int t = solution(2, 10, v); // 8
}