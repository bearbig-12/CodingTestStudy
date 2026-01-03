/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int ans;
string str;
set<pair<int, string>> vis;
int DFS(int index, int change_count)
{
	if (vis.count({ index, str }))
	{
		return ans;
	}
	vis.insert({ index, str });

	if (index == change_count)
	{
		ans = max(ans, stoi(str));
		return ans;
	}

	for (int i = 0; i < str.length()-1; ++i)
	{
		for (int j = i + 1; j < str.length(); ++j)
		{
			swap(str[i], str[j]);
			DFS(index + 1, change_count);
			swap(str[i], str[j]);
		}
	}

	return ans;
}

vector<int> num{ 1,2,3 };
vector<int> v(3, 0);
vector<bool> visited(3, false);


int main(int argc, char** argv)
{


	int test_case;
	int T;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	int change_count;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		cin >> str >> change_count;
		if (change_count > str.size())
		{
			change_count = str.size();
		}

		vis.clear();
		DFS(0, change_count);

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}