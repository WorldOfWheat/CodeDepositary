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

vector<int> ve;
vector<int> pf;
vector<int> dp((int) 2e5 + 1);

void solve() {

    int n, m;
    cin >> n >> m;
    ve.resize(n);
    pf.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    pf[0] = ve[0];
    rep (i, 1, n) {
        pf[i] = pf[i-1] + ve[i];
    }

    dp[m] = pf[m-1];
    rep2 (i, m+1, n) {
        dp[i] = max(dp[i-1], dp[i-m-1] + pf[i-1] - pf[i-m-1]);
    }
    cout << (dp[n]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
