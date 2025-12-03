#include <string>
#include <vector>

using namespace std;

// Key Point
// 옐로우는 무조건 브라운 으로 감싸져 있어야 하므로 height는 무조건 3이상이다.
// width >= height
// 옐로우는 브라운으로 감싸져 있다. ( 옐로우 = (width - 2) * (height - 2))
// total = 브라운 + 옐로우
vector<int> solution(int brown, int yellow) {
    vector<int> answer;


    int total = brown + yellow;
    
    // 일단 너비 * 높이가 토탈이 되는 약수를 찾아야한다
    for (int height = 3; height <= total; ++height)
    {
        int width = 0;
        if (total % height == 0)
        {
            width = total / height;
        }

        if (width >= height)
        {
            if ((width - 2) * (height - 2) == yellow)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }



    return answer;
}


int main()
{
    int b = 24;
    int y = 24;

    solution(b, y);

}