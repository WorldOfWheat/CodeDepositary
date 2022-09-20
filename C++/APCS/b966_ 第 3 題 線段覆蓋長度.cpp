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

    ve.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ve[i] = mp(a, b);
    }
    sort(ve.begin(), ve.end());
    int ans = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (ve[i].F >= last) {
            ans += ve[i].S - ve[i].F;
            last = ve[i].S;
        } else if (ve[i].S >= last) {
            ans += ve[i].S - last;
            last = ve[i].S;
        }
    }
    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
