#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
#define rep(x, y) for (int x = 0; x < y; x++)

using namespace std;

int n, m;
vector<string> ve;
unordered_map<string, int> ump;

void solve() {

    cin >> n >> m;
    ve.resize(m);
    rep(i, m) {
        cin >> ve[i];
    }
    int cnt = 0;
    rep(i, n) {
        if (!ump[ve[i]]) cnt++;
        ump[ve[i]]++;
    }
    int ans = (cnt == n);
    int l = 0, r = n;
    while (r < m) {
        ump[ve[l]]--;
        if (!ump[ve[l]]) cnt--;
        if (!ump[ve[r]]) cnt++;
        ump[ve[r]]++;
        ans += (cnt == n);
        l++;
        r++;
    }
    cout << ans << ln;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
