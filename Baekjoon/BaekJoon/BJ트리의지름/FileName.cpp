#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


static int N;
vector<vector<pair<int, int>>> v;
vector<bool> visited;
vector<int> m_distance;

// 백준 1167번
// 핵심 아이디어는 임의의 노드에서 가장 긴 경로로 연결된 노드는 트리의 지름에 해당하는 두 노드 중 하나다.

void BFS(int n)
{
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto e : v[curr])
		{
			if (visited[e.first] != true)
			{
				q.push(e.first);
				visited[e.first] = true;
				m_distance[e.first] = m_distance[curr] + e.second;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N + 1);
	visited = vector<bool>(N + 1, false);
	m_distance = vector<int>(N + 1, 0);

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		while (true)
		{
			int e, d;
			cin >> e;

			if (e == -1)
			{
				break;
			}
			cin >> d;
			v[k].push_back({ e,d });
		}
	}

	BFS(1);
	int max = max_element(m_distance.begin(), m_distance.end()) - m_distance.begin();

	fill(visited.begin(), visited.end(), false);
	fill(m_distance.begin(), m_distance.end(), 0);

	BFS(max);

	max = *max_element(m_distance.begin(), m_distance.end());
	cout << max;


}