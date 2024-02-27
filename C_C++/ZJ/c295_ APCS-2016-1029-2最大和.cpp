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

vector<int> ve;
vector<int> ve2;

void solve() {

    int n, m;
    cin >> n >> m;
    rep (i, 0, n) {
        int maxi = -1e18;
        rep (i, 0, m) {
            int a;
            cin >> a;
            maxi = max(maxi, a);
        }
        ve.pb(maxi);
    }
    int sum = 0;
    for (auto i : ve) {
        sum += i;
    }
    for (auto i : ve) {
        if (sum % i == 0) {
            ve2.push_back(i);
        }
    }
    cout << (sum) << ln;
    if (ve2.empty()) {
        cout << -1 << ln;
        return;
    }
    rep (i, 0, ve2.size()) {
        if (i != 0) {
            cout << sp;
        }
        cout << (ve2[i]);
    }
    cout << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
