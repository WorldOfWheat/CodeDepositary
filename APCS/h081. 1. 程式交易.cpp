#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
vector<int> ve;

void solve() {

    cin >> n >> m;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int now = ve[0];
    int last = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (now != -1 && ve[i] >= now + m) {
            ans += ve[i] - now;
            last = ve[i];
            now = -1;
        }
        else if (now == -1 && ve[i] <= last - m) {
            now = ve[i];
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
