#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
int dp[(int) 1e6 + 1];

void solve() {

    int n, m;
    cin >> n >> m;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    for (auto &a : dp) {
        a = 1e18;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ve[i] > j) {
                continue;
            }
            dp[j] = min(dp[j], dp[j - ve[i]]  + 1);
        }
    }
    if (dp[m] == 1e18) {
        cout << "-1" << ln;
        return;
    }
    cout << (dp[m]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
