#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n;
vector<pii> ve;

bool cmp (pii x, pii y) {
    return (x.S < y.S);
}

void solve () {

    cin >> n;
    ve.resize (n);
    int sum = 0;
    for (int i = 0 ; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ve[i] = {a, b};
        sum += ve[i].F;
    }
    sort(ve.begin(), ve.end(), cmp);
    int l = 0, r = n - 1;
    int ans = 0;
    int now = 0;
    while (l <= r) {
        if (now >= ve[l].S) {
            ans += ve[l].F;
            now += ve[l].F;
            l++;
        }
        else {
            int remain = min( ve[r].F, ve[l].S - now );
            ans += remain * 2;
            ve[r].F -= remain;
            now += remain;
            if (ve[r].F == 0) {
                r--;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
