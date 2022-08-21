#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep2(x, y, z) for (int x = y; x >= 0; x--)
#define ln "\n"
#define sp " "

using namespace std;

vector<pii> ve;
int dp[100+1][(int) 1e5 + 1];
int dp2[(int) 1e5 + 1];

void solve() {

    int n, m;
    cin >> n >> m;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i].F >> ve[i].S;
    }
    rep2 (i, 1, n) {
        pii top = ve[i-1];
        rep2 (j, 1, m) {
            if (j < top.F) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            int remain = (j - top.F);
            dp[i][j] = max(dp[i-1][j], dp[i-1][remain] + top.S);
        }
    }

    cout << (dp[n][m]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////