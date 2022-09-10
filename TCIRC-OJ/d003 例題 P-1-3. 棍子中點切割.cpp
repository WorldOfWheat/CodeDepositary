#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "

using namespace std;

vector<int> ve;

int dfs(int l, int r) {
    if (r - l <= 1) {
        return 0;
    }
    //cerr << l << sp << r <<ln;
    int mid = (ve[l] + ve[r]) >> 1;
    auto it = upper_bound(ve.begin(), ve.end(), mid);
    it--;
    int d = distance(ve.begin(), it) + 1;
    if (ve[d-1] - ve[l] >= ve[r] - ve[d]) {
        d--;
    }
    return (ve[r] - ve[l]) + dfs(l, d) + dfs(d, r);
}

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n+2);
    ve[0] = 0;
    ve[n+1] = m;
    rep2 (i, 1, n) {
        cin >> ve[i];
    }
    cout << dfs(0, n+1) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
