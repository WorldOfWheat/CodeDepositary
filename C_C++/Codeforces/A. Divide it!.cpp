#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep2(x, y, z) for (int x = y; x >= 0; x--)
#define ln "\n"
#define sp " "

using namespace std;

int dfs(int x, int y) {
    if (x == 1) {
        return y;
    }
    if (x % 2 == 0) {
        return dfs(x / 2, y + 1);
    }
    if (x % 3 == 0) {
        return dfs(2 * x / 3, y + 1);
    }
    if (x % 5 == 0) {
        return dfs(4 * x / 5, y + 1);
    }
    return -1;
}

void solve() {

    int n;
    cin >> n;
    cout << (dfs(n, 0)) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
