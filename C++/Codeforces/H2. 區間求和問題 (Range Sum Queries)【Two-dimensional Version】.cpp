#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define sp " "
#define ln "\n"

using namespace std;

int n, m, o;
VV ve;
VV pf;

void solve() {

    cin >> n >> m;

    ve.resize(n, V(m));
    pf.resize(n + 1, V(m + 1));

    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }

    rep2 (i, 1, n) {
        rep2 (j, 1, m) {
            pf[i][j] = pf[i-1][j] + (pf[i][j-1] - pf[i-1][j-1]) + ve[i-1][j-1];
        }
    }

    cin >> o;

    rep (i, 0, o) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a++;
        b++;
        c++;
        d++;
        cout << (pf[c][d] - pf[c][b-1] - pf[a-1][d] + pf[a-1][b-1]) << ln;
    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
