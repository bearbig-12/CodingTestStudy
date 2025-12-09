#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 해당 문제는 최소신장트리를 사용한 문제이며, 크루스칼 알고리즘( 유니온 파인드)을 알아두는게 중요하다.

// 유니온 파인드
// 두 노드가 같은 그룹에 속하는지 판별하는 알고리즘
// Find 와 UnionSet으로 나뉘어진다.
// Find 에서는 재귀함수를 사용하여 현재 노드의 부모노드로 계속해서 타고 올라간다. 종료 조건은 부모가 자기 자신일때
// UnionSet 에서는 두노드의 부모노드를 찾는다, 만약 부모 노드가 다르다면, 두노드를 합친다 = 부모를 같게
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
    else
    {
        return parent[x] = Find(parent[x]);
    }
}

bool UnionSet(int a, int b)
{
    a = Find(a);
    b = Find(b);

    // 부모가 같다 사이클이 형성되었다
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

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
	vector<Edge> edges;
    

    for (auto c : costs)
    {
        edges.push_back({ c[0], c[1], c[2] });
    }
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end(), comp);

    int cnt = 0;
    for (auto i : edges)
    {
        if (UnionSet(i.nodeA, i.nodeB))
        {
            answer += i.cost;
            cnt++;

            if (cnt == n-1)
            {
                break;
            }
        }
    }

}

int main()
{
    vector<vector<int>> s = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    solution(4, s);
}