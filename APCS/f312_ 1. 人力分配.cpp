#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

void solve() {

    int a, b, c;
    int d, e, f;
    int n;
    cin >> a >> b >> c >> d >> e >> f >> n;
    int ans = -1e18;
    int l = n, r = 0;
    while (l >= 0) {
        //cout << (a*(l*l)+b*l+c) << " " << (d*(r*r)+e*l+f) << "\n";
        ans = max(ans, (a*(l*l)+b*l+c) + (d*(r*r)+e*r+f) );
        l--;
        r++;
    }
    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
