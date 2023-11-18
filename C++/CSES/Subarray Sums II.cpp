#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n, m;
map<int, int> mp;

void solve() {

    cin >> n >> m;
    int ans = 0;
    int sum = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        ans += mp[sum - m];
        mp[sum]++;
    }
    cout << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
