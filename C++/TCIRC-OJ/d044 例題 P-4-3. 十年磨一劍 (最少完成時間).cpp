#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int ans = ve[0];
    rep (i, 1, n) {
        ve[i] += ve[i-1];
        ans += ve[i];
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
