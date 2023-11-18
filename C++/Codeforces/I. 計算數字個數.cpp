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

vector<int> ve((int) 1e6 + 1);

void solve() {

    int n;
    cin >> n;
    rep (i, 0, n) {
        int a;
        cin >> a;
        ve[a]++;
    }
    int m;
    cin >> m;
    rep (i, 0, m) {
        int a;
        cin >> a;
        if ( a > (int) 1e6) {
            cout << 0 << ln;
            continue;
        }
        cout << (ve[a]) << ln;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
