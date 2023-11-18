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
vector<int> ve;

void solve() {

    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ve[i] == 0) {
            if (i != 0 && i != n-1) {
                ans += min(ve[i-1], ve[i+1]);
            }
            else if (i == 0) {
                ans += ve[i+1];
            }
            else {
                ans += ve[i-1];
            }
        }
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
