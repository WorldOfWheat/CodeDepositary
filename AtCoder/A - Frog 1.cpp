#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
vector<int> dp;

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    dp.resize(n+1);
    rep(i, 0, n) {
        cin >> ve[i];
    }
    dp[2] = abs(ve[0] - ve[1]);
    rep2(i, 3, n) {
        int a = dp[i-1] + abs(ve[i-1] - ve[i-1-1]);
        int b = dp[i-2] + abs(ve[i-1] - ve[i-2-1]);
        dp[i] = min(a, b);
    }
    cout << (dp[n]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
