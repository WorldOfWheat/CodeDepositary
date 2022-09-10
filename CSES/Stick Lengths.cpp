#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;
vector<int> ve;

void solve() {

    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int median = ve[n/2];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (abs(median - ve[i]));
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
