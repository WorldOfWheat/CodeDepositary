#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n;
vector<int> ve;
vector<int> dp;

void solve() {

    cin >> n;
    ve.resize(n);
    dp.resize(n+1);
    for (int i = 0 ; i < n; i++) {
        cin >> ve[i];
        dp[ve[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans += dp[i-1] > dp[i];
    }
    cout << ans << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
