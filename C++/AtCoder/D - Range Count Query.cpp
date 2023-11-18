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

using namespace std;

vv ve(1);

void solve() {

    int n;
    cin >> n;
    ve.resize(n+1);

    rep (i, 0, n) {
        int a;
        cin >> a;
        ve[a].pb(i);
    }

    int m;
    cin >> m;

    rep (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        auto it = lower_bound(ve[c].begin(), ve[c].end(), a-1);
        auto it2 = lower_bound(ve[c].begin(), ve[c].end(), b);
        cout << (distance(it, it2)) << ln;
    }



}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
