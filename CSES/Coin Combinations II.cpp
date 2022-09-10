#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
vector<int> dp;

void solve() {

    int n, m;
    cin >> n >> m;
    ve.resize(n);
    dp.resize(m+1);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < ve[i]) {
                continue;
            }
            dp[j] += dp[j - ve[i]];
            dp[j] %= (int) (1e9 + 7);
        }
    }
    cout << (dp[m]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
