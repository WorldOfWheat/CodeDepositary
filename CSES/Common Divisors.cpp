#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve((int) 1e6+1);

void solve() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ve[a]++;
    }
    int ans = 1;
    for (int i = 1; i <= 1e6+1; i++) {
        int cnt = 0;
        for (int j = i; j <= 1e6+1; j+=i) {
            cnt += ve[j];
        }
        if (cnt >= 2) {
            ans = max(ans, i);
        }
    }
    cout << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
