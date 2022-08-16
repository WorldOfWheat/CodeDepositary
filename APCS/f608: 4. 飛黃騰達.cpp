#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<pii> ve;
vector<int> ve2;

void solve() {

    cin >> n;
    ve.resize(n);
    ve2.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].F >> ve[i].S;
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < n; i++) {
        ve2[i] = ve[i].S;
    }

    vector<int> dp;
    dp.resize(n+1);

    vector<int> dp2;

    dp[1] = 1;
    dp2.push_back(ve2.front());

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (ve2[i-1] < dp2.back()) {
            auto it = upper_bound(dp2.begin(), dp2.end(), ve2[i-1]);
            *it = ve2[i-1];
            dp[i] = distance(dp2.begin(), it) + 1;
        }
        else {
            ans++;
            dp2.push_back(ve2[i-1]);
            dp[i] = ans;
        }
    }
    cout << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
