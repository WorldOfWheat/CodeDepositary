#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define ln '\n'
#define sp " "

using namespace std;

struct act {
    int a;
    int b;
    int c;
};
vector<act> ve;
int dp[(int) 1e5][3+1];

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    rep(i, 0, n) {
        int a, b, c;
        cin >> a >> b >> c;
        ve[i].a = a;
        ve[i].b = b;
        ve[i].c = c;
    }
    dp[1][1] = ve[0].a;
    dp[1][2] = ve[0].b;
    dp[1][3] = ve[0].c;
    rep2(i, 2, n) {
        int a = dp[i-1][1];
        int b = dp[i-1][2];
        int c = dp[i-1][3];
        dp[i][1] = ve[i-1].a + max(b, c);
        dp[i][2] = ve[i-1].b + max(a, c);
        dp[i][3] = ve[i-1].c + max(a, b);
    }
    cout << (max({dp[n][1], dp[n][2], dp[n][3]})) << ln;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
