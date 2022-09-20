#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n, m;
map<int, int> table;

int dfs(int x, int len) {
    if (table[x] != 0 || x == 1) {
        return table[x];
    }
    table[x] = ((x % 2) ? dfs(3*x+1, 0) : dfs(x/2, 0)) + 1;
    return table[x] + len;
}

void solve() {

    cin >> m;
    int ans = -1e18;
    for (int i = min(n, m); i <= max(n, m); i++) {
        ans = max(ans, dfs(i, 0)+1 );
    }
    cout << n << sp << m << sp << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    table[1] = 0;
    table[2] = 1;
    table[4] = 2;
    while (cin >> n) solve();

    return 0;
}
