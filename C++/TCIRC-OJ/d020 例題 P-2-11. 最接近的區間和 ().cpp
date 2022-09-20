#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;
set<int> se;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    int ans = 0;
    int pf = 0;
    rep (i, 0, n) {
        pf += ve[i];
        int re = pf - m;
        auto it = se.lower_bound(re);
        if (it != se.end()) {
            ans = max(ans, pf - *it);
        }
        se.insert(pf);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
