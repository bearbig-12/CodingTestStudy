#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> name;

    for (string n : participant)
    {
        if (name.find(n) == name.end())
        {
            name.insert({ n, 1 });
        }
        else
        {
            name[n] += 1;
        }
        
    }

    for (string n : completion)
    {
        if (name.find(n) != name.end())
        {
            name[n] -= 1;
        }
    }

    for (auto n : name)
    {
        if (n.second > 0)
        {
            answer = n.first;
        }
    }
    return answer;
}


string solution2(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> hash;

    for (auto i : participant)
    {
        // 이 이름이 처음 나오는지 확인 
        // Find 는 찾는 원소가 없을 경우 end를 반환한다
        if (hash.find(i) == hash.end())
        {
            hash[i] = 1;
        }
        else
        {
            hash[i]++;

        }
    }

    for (auto i : completion)
    {
        hash[i]--;
    }


    for (auto i : hash)
    {
        if (i.second >= 1)
        {
            answer = i.first;
        }
    }
    return answer;
}

int main()
{
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };

     solution(participant, completion);

}