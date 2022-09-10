#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;
vector<pii> ve;

void solve() {

    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].F;
    }
    for (int i = 0; i < n; i++) {
        cin >> ve[i].S;
    }
    sort(ve.begin(), ve.end(), [](pii x, pii y) {
        return (x.F * y.S) < (x.S * y.F);
    });
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        ans += ve[i].S * now;
        now += ve[i].F;
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
