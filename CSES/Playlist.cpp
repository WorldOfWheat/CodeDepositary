#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n;
vector<int> ve;
map<int, int> mp;

void solve() {

    cin >> n;
    ve.resize(n);
    int cnt = 0;
    int ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        int top = ve[i];
        l = max(l, mp[top]);
        ans = max(ans, i-l+1);
        mp[top] = i+1;
    }
    cout << ans << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
