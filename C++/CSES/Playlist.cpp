#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<int> ve;
map<int, int> mp;

void solve() {

    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        l = max(l, mp[ve[i]]);
        ans = max(ans, i - l + 1);
        mp[ve[i]] = i+1;
    }
    cout << ans << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
