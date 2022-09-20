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

V ve;
V ve2;
V pf;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n);
    ve2.resize(m);
    int sum = 0;
    rep (i, 0, n) {
        cin >> ve[i];
        sum += ve[i];
        pf.pb(sum);
    }
    rep (i, 0, m) {
        cin >> ve2[i];
    }
    int l = 0;
    int now = 0;
    while (l != m) {
        if (now != 0) {
            ve2[l] += pf[now-1];
        }
        while (ve2[l] > pf.back()) {
            ve2[l] -= pf.back();
        }
        auto it = lower_bound(pf.begin(), pf.end(), ve2[l]);
        now = it - pf.begin() + 1;
        now %= n;
        l++;
    }
    cout << now << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
