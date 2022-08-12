#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n, m;
vector<pii> ve;
int dp[100000+1];

void solve() {

    cin >> n >> m;
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i].F;
    }
    for (int i = 1; i <= n; i++) {
        cin >> ve[i].S;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (ve[i].F > j) {
                continue;
            }
            int remain = j - ve[i].F;
            dp[j] = max(ve[i].S + dp[remain], dp[j]);
        }
    }
    cout << dp[m] << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
