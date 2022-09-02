#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define M (int) 1e9 + 7

using namespace std;

multiset<int> ms;
multiset<int> ms2;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    rep (i, 0, n) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    rep (i, 0, m) {
        int a;
        cin >> a;
        ms2.insert(a);
    }
    int ans = 0;
    for (auto a : ms) {
        int re = k - a;
        auto l = ms2.lower_bound(re);
        auto r = ms2.upper_bound(re);
        ans += distance(l, r);
    }
    cout << ans << ln;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
