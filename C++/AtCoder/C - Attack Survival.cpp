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
#define MAX (int) 1e5 + 1

using namespace std;

vector<int> ve(MAX);

void solve() {

    int n, m, k;
    cin >> n >> m >> k;
    rep (i, 0, k) {
        int a;
        cin >> a;
        ve[a-1]++;
    }

    rep (i, 0, n) {
        cout << (m - (k - ve[i]) > 0 ? "Yes" : "No") << ln;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
