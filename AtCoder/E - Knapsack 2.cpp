#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

vector<pii> ve;
vector<int> dp;

void solve() {

    int n, m;
    cin >> n >> m;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i].F >> ve[i].S;
    }
    dp.resize((int) 1e5, 1e18);
    dp[0] = 0;
    rep2 (i, 1, n) {
        pii top = ve[i-1];
        rrep (j, (int) 1e5, top.S) {
            dp[j] = min(dp[j], dp[j - top.S] + top.F);
        }
    }
    int ans = 0;
    rep2 (i, 1, (int) 1e5) {
        if (dp[i] <= m) {
            ans = max(ans, i);
        }
    }
    cout << (ans) << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
