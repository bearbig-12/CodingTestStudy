#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 해당 문제는 최소신장트리를 사용한 문제이며, 크루스칼 알고리즘( 유니온 파인드)을 알아두는게 중요하다.
int parent[101];
struct Edge {
    int nodeA;
    int nodeB;
    int cost;
};

int Find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    return parent[x] = Find(parent[x]);
}

bool UnionSet(int a, int b)
{
    a = Find(a);
    b = Find(b);

    // 부모가 같다 = 사이클이다
    if (a == b)
    {
        return false;
    }

    parent[b] = a;
    return true;
}

bool comp(const Edge& a, const Edge& b)
{
    return a.cost < b.cost;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
	vector<Edge> edges;

    for (auto cost : costs)
    {
        edges.push_back({ cost[0], cost[1], cost[2] });
    }

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), comp);

    int cnt = 0;
    for (auto e : edges)
    {
        if (UnionSet(e.nodeA, e.nodeB))
        {
            answer += e.cost;
            cnt++;

            // 최소신장트리는 총간선 갯수가 총 노드 갯수 보다 1개 적다
            if (cnt == n - 1)
            {
                break;
            }
        }
    }


    return answer;
}

int main()
{
    vector<vector<int>> s = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    solution(4, s);
}