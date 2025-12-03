#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int number = nums.size() / 2;

    unordered_map<int, int> hash;

    for (auto i : nums)
    {
        if (hash.find(i) == hash.end())
        {
            hash[i] = 1;
        }
    }

   answer  = min((int)hash.size(), number);


    return answer;
}

int main()
{
    vector<int> nums = { 3,1,2,3 };
    vector<int> nums2 = { 3,3,3,2,2,4 };
    vector<int> nums3 = { 3,3,3,2,2,2 };

    cout << solution(nums3) << endl;
}