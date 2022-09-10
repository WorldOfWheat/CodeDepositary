#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;
map<int, int> ma;

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    int ans = 0;
    int l = 0;
    rep (r, 0, n) {
        int top = ve[r];
        ma[top]++;
        while (ma[top] > 1) {
            ma[ve[l]]--;
            l++;
        }
        //cerr << l << sp << r << ln;
        ans = max(ans, r - l + 1);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
