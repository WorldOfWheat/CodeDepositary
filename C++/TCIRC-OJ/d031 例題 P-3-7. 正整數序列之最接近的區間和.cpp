#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    int l = 0, r = 0;
    int maxi = 0;
    int ans = 0;
    int sum = 0;
    while (r != n) {
        sum += ve[r++];
        while (sum > m) {
            sum -= ve[l++];
        }
        if (maxi < sum) {
            maxi = sum;
            ans = 1;
            continue;
        }
        if (maxi == sum) {
            ans++;
        }
    }
    cout << ans << ln << maxi << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
