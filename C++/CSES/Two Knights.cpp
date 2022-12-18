#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18

using namespace std;

int n;

void solve() {

    cin >> n;

    cout << 0 << '\n';
    rep2 (i, 2, n) {
        int ans = (i * i) * ((i * i) - 1) / 2;
        ans -= 4 * (i - 2) * (i - 1);
        cout << ans << '\n';
    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
