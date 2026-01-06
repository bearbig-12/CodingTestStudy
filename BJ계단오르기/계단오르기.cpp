#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	
	int DP[301]{ 0 };

	int score;

	vector<int> scores(num);
	for (int i = 0; i < num; ++i) cin >> scores[i];

	DP[0] = scores[0];
	DP[1] = scores[0] + scores[1];
	DP[2] = max(scores[0] + scores[2], scores[1] + scores[2]);

	// 연속계단 방지 플래그
	int n = 0;
	for (int i = 3; i < num; ++i)
	{
		// 연속 3칸이 안되는걸 이해해야함
		// i 까지 도달하는 방법은 총 2가지 i-2 -> i로 2칸 점프
		// i-3 에서 2칸점프 -> 한칸 점프
		DP[i] = max(DP[i - 2] + scores[i], DP[i - 3] + scores[i - 1] + scores[i]);

	}



	cout << DP[num - 1];

}