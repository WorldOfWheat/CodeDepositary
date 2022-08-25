#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<pii>>
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

int n;
set<int> se;
set<int> se2;

void solve() {

    se.clear();
    se2.clear();

    rep (i, 0, n) {
        int a;
        cin >> a;
        se.insert(a);
    }

    rep (i, 0, n) {
        int a;
        cin >> a;
        se2.insert(a);
    }

    int ans = 0;
    for (auto it = se.begin(); it != se.end(); it++) {
        ans += (se2.count(*it));
    }
    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t >> n;
    while (t--) solve();

    return 0;

}
