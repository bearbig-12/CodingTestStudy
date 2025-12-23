#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;

        vector<long long> price(N);
        for (int i = 0; i < N; ++i) cin >> price[i];

        long long maxSoFar = 0;
        long long profit = 0;

        for (int i = N - 1; i >= 0; --i) {
            if (price[i] > maxSoFar) {
                maxSoFar = price[i];
            }
            else {
                profit += (maxSoFar - price[i]);
            }
        }

        cout << "#" << tc << " " << profit << "\n";
    }

    return 0;
}
