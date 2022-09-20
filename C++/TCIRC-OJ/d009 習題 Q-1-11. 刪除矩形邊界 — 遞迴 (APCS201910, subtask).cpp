#include <bits/stdc++.h>
#define int long long
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

vv ve;
int ans = 1e18;;

void dfs(int l, int r, int u, int d, int value) {
    if (r - l == 0 || d - u == 0) {
        ans = min(ans, value);
        return;
    }

    int zero = 0;
    int one = 0;
    rep2 (i, l, r) {
        one += ve[u][i];
        zero += ve[u][i] ^ 1;
    }
    dfs(l, r, u+1, d, value+min(zero, one));

    zero = 0;
    one = 0;
    rep2 (i, l, r) {
        one += ve[d][i];
        zero += ve[d][i] ^ 1;
    }
    dfs(l, r, u, d-1, value+min(zero, one));

    zero = 0;
    one = 0;
    rep2 (i, u, d) {
        one += ve[i][l];
        zero += ve[i][l] ^ 1;
    }
    dfs(l+1, r, u, d, value+min(zero, one));

    zero = 0;
    one = 0;
    rep2 (i, u, d) {
        one += ve[i][r];
        zero += ve[i][r] ^ 1;
    }
    dfs(l, r-1, u, d, value+min(zero, one));
}

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n);
    for (auto &i : ve) {
        i.resize(m);
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }
    dfs(0, m-1, 0, n-1, 0);
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
