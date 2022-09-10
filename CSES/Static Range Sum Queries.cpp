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

vector<int> ve((int) 2e5 + 1);
vector<int> pf((int) 2e5 + 1);

void solve() {

    int n, m;
    cin >> n >> m;
    rep (i, 0, n) {
        cin >> ve[i];
    }

    pf[1] = ve[0];
    rep2 (i, 2, n) {
        pf[i] = pf[i-1] + ve[i-1];
    }
    rep (i, 0, m) {
        int a, b;
        cin >> a >> b;
        cout << (pf[b] - pf[a-1]) << ln;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
