#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<vector<char>> ve(1000+1, vector<char>(1000+1));
vector<vector<int>> dp(1000+1, vector<int>(1000+1));

void solve() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ve[i][j];
        }
    }
    if (ve[0][0] == '*') {
        cout << (0) << ln;
        return;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == 1 && j == 1) {
                continue;
            }
            if (ve[i-1][j-1] == '*') {
                continue;
            }

            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= (int) 1e9 + 7;

        }
    }
    cout << (dp[n][n]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
