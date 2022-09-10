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
vector<int> ve_mini;

void solve() {

    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    ve_mini.push_back(ve.front());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (ve_mini.back() < ve[i]) {
            ans++;
            ve_mini.push_back(ve[i]);
        } else {
            auto it = lower_bound(ve_mini.begin(), ve_mini.end(), ve[i]);
            *it = ve[i];
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
