#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<int> ve;
vector<int> ve2;

void solve() {

    cin >> n;
    ve.resize(n);
    ve2.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ve[a-1] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans += (ve[i] < ve[i-1]);
    }
    cout << ans << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
