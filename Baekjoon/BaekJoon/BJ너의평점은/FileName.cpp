#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	float score;
	string grade;

	float totalScore = 0;
	float sum = 0;

	for (int i = 0; i < 20; ++i)
	{
		cin >> s >> score >> grade;

		if (grade == "P")
		{
			continue;
		}
		totalScore += score;

		if (grade == "A+")
		{
			sum += score * 4.5f;
		}
		else if (grade == "A0")
		{
			sum += score * 4.0f;
		}
		else if (grade == "B+")
		{
			sum += score * 3.5f;
		}
		else if (grade == "B0")
		{
			sum += score * 3.0f;
		}
		else if (grade == "C+")
		{
			sum += score * 2.5f;
		}
		else if (grade == "C0")
		{
			sum += score * 2.0f;
		}
		else if (grade == "D+")
		{
			sum += score * 1.5f;
		}
		else if (grade == "D0")
		{
			sum += score * 1.0f;
		}
		else if (grade == "F")
		{
			sum += score * 0.0f;
		}
		


	}
	float answer = sum / totalScore;
	cout << answer;
}