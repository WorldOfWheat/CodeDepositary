#include <bits/stdc++.h>
#define int long long
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

const vector<int> ve = {1, 5, 10, 25, 50};
int n;
vector<int> dp(7489+1);

void solve() {

    cout << (dp[n]) << ln;

}

void init() {

    dp[0] = 1;
    rep (i, 0, 5) {
        int top = ve[i];
        rep2 (j, top, 7489) {
            dp[j] += dp[j - top];
        }
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    while (cin >> n) solve();

    return 0;

}
