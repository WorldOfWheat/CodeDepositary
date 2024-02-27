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

vv ve;
V mini;
V maxi;

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    mini.resize(n);
    maxi.resize(n);
    for (auto &i : ve) {
        i.resize(n);
    }
    rep (i, 0, n) {
        rep (j, 0, n) {
            int a;
            cin >> a;
            ve[i][j] = a;
        }
    }
    rep (i, 0, n) {
        int mi = 1e18;
        int ma = -1e18;
        rep (j, 0, n) {
            mi = min(ve[j][i], mi);
            ma = max(ve[i][j], ma);
        }
        mini[i] = mi;
        maxi[i] = ma;
    }
    rep (i, 0, n) {
        rep (j, 0, n) {
            int top = ve[i][j];
            if (top == mini[j] && top == maxi[i]) {
                cout << i << sp << j << ln;
                return;
            }
        }
    }
    cout << "NO" << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
