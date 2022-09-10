#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m, k;

void solve() {

    cin >> n >> m >> k;
    if (n + k <= m) {
        cout << 0 << "\n";
        return;
    } else {
        int l = 0, r = k;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (n+mid > m+(k-mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << (k - r) << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
