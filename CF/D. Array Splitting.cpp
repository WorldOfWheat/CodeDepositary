#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n, m;
vector<int> ve;
vector<int> sf;

void solve() {

    cin >> n >> m;
    ve.resize(n);
    sf.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        sum += ve[i];
    }
    for (int i = 1; i <= n-1; i++) {
        sf[i] = sf[i-1] + ve[n-i];
    }
    sort(sf.rbegin(), sf.rend()-1);
    int ans = sum;
    for (int i = 1; i < m; i++) {
        ans += sf[i];
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

