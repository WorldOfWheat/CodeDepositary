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
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        maxi = max(maxi, ve[i]);
    }
    sort(ve.begin(), ve.end());
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        //cerr << dp[i] << ln;
        if (dp[i] < ve[i]) {
            cout << dp[i] << ln;
            return;
        }
        dp[i+1] = dp[i] + ve[i];
    }
    cout << dp[n] << ln;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
