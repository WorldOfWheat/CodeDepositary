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
    sort(ve.begin(), ve.end());
    dp[0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int top = ve[j] + i;
            if (top > m) {
                break;;
            }
            dp[top] += dp[i];
            dp[top] %= (int) (1e9 + 7);
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
