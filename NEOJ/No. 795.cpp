#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "
#define maxn (int) 2e5 + 1

using namespace std;

vector<pii> ve;
set<pii> se;

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        int a, b;
        cin >> a >> b;
        ve[i] = {a, b};
    }

    sort(ve.begin(), ve.end());
    int ans = LLONG_MAX;
    int j = 0;
    rep (i, 0, n) {

        int k = ceil(sqrt(ans));
        while (ve[i].F - ve[j].F >= k) {
            se.erase({ve[j].S, ve[j].F});
            j++;
        }
        auto it = se.lower_bound({ve[i].S - k, ve[i].F});
        auto it2 = se.upper_bound({ve[i].S + k, ve[i].F});
        for (auto j = it; j != it2; j++) {
            int a = ve[i].F - j->S;
            int b = ve[i].S - j->F;
            ans = min(ans, 1ll * a * a + 1ll * b * b);
        }
        se.insert({ve[i].S, ve[i].F});

    }
    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
