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

vector<pii> ve;

bool cmp(pii x, pii y) {
    return (x.F * y.S < x.S * y.F);
}

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i].F;
    }
    rep (i, 0, n) {
        cin >> ve[i].S;
    }
    sort(ve.begin(), ve.end(), cmp);
    int sum = ve[0].F;
    int ans = 0;
    rep (i, 1, n) {
        ans += (ve[i].S * sum);
        sum += ve[i].F;
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
