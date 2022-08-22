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

int n;
vector<int> ve;
int dp[(int) 1e6 + 1];

void solve() {

    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    dp[1] = max(0ll, ve[0]);
    rep2 (i, 2, n) {
        dp[i] = max(ve[i-1] + dp[i-2], dp[i-1]);
    }
    cout << (dp[n]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

int n;
vector<int> ve;
int dp[(int) 1e6 + 1][1];

void solve() {

    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    dp[1][0] = 0;
    dp[1][1] = max(0ll, ve[0]);
    rep2 (i, 2, n) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = max(dp[i-2][1] + ve[i-1], dp[i-1][0]);
    }
    cout << (max(dp[n][0], dp[n][1])) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
