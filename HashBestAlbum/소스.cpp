#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    // 플레이 횟수가 같다면 인덱스 번호가 작은 순으로 정열
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;
    }
}

// 노래 장르별 총합 정렬
bool comp2(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) 
{
    // 노래 장르별 총합
    unordered_map<string, int> total_play;
    // 노래 장르, 플레이 횟수, 인덱스 번호
    unordered_map<string, vector<pair<int, int>>> all;

    for (int i = 0; i < genres.size(); ++i)
    {
        if (total_play.find(genres[i]) != total_play.end())
        {
            total_play[genres[i]] = plays[i];
        }
        else
        {
            total_play[genres[i]] += plays[i];
        }

        all[genres[i]].push_back({ plays[i], i });
    }





}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> playes = { 500, 600, 150, 800, 2500 };

    vector <int> a;
    a = solution(genres, playes);

    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << endl;
    }
    
}

