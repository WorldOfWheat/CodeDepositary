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
multiset<int> ms;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n+1);
    rep2 (i, 1, n) {
       cin >> ve[i];
    }
    rep2 (i, 1, m) {
        ms.insert(ve[i]);
    }
    int ans = 0;
    rep2 (i, m+1, n) {
        ans = max(ans, (*(ms.rbegin())) - (*(ms.begin())) );
        ms.insert(ve[i]);
        ms.erase(ms.find(ve[i-m]));
    }
    ans = max(ans, (*(ms.rbegin())) - (*(ms.begin())) );
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
