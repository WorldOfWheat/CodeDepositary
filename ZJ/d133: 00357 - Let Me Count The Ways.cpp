#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const int coins[5] = {1, 5, 10, 25, 50};
    long long dp[30000+1] = {1};
    for (auto &a : coins) {
        for (int i = a; i <= 30000; i++) {
            dp[i] += dp[i-a];
        }
    }
    int n;
    while (cin >> n) {
        if (dp[n] == 1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    }

    return 0;
}
