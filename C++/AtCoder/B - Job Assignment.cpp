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
#define MAX (int) 2e6 + 1

using namespace std;

vector<int> ve;
vector<int> ve2;

void solve() {

    int n;
    cin >> n;
    rep (i, 0, n) {
        int a, b;
        cin >> a >> b;
        ve.pb(a);
        ve2.pb(b);
    }
    int ans = 1e18;
    rep (i, 0, n) {
        rep (j, 0, n) {
            int sum = 0;
            if (i == j) {
                sum = ve[i] + ve2[j];
            }
            else {
                sum = max(ve[i], ve2[j]);
            }
            //cerr << sum << ln;
            ans = min(ans, sum);
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
