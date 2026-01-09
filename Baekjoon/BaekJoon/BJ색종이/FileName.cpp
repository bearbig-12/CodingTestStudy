#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool board[101][101] = {}; 

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        for (int dx = 0; dx < 10; ++dx) {
            for (int dy = 0; dy < 10; ++dy) {
                board[x + dx][y + dy] = true;
            }
        }
    }

    int area = 0;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            if (board[x][y]) area++;
        }
    }

    cout << area;
    return 0;
}
