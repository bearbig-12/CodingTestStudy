#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

bool comp(const pair<string , pair<int, int>>& a, const pair<string, pair<int, int>>& b)
{
    // 플레이 횟수가 같다면 인덱스 번호가 작은 순으로 정열
    if (a.second.first == b.second.first)
    {
        return a.second.second < b.second.second;
    }
    else
    {
        return a.second.first > b.second.first;
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
    vector<pair<string, pair<int, int>>> all;

    vector<int> answer;

    for (int i = 0; i < genres.size(); ++i)
    {
        if (total_play.find(genres[i]) == total_play.end())
        {
            total_play[genres[i]] = plays[i];
        }
        else
        {
            total_play[genres[i]] += plays[i];
        }

        all.push_back( {genres[i], {plays[i], i}});
    }

    vector<pair<string, int>> temp;
    vector<pair<string , pair<int, int>>> temp2;

    for (auto s : total_play)
    {
        temp.push_back(s);
    }


    sort(temp.begin(), temp.end(), comp2);
    sort(all.begin(), all.end(), comp);

    for (int i = 0; i < temp.size(); ++i)
    {
        int cnt = 0;
        for (int j = 0; j < all.size(); ++j)
        {
            if (temp[i].first == all[j].first && cnt < 2)
            {
                answer.push_back(all[j].second.second);
                cnt++;
            }
           
            
        }
        cnt = 0;
    }



    return answer;



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

