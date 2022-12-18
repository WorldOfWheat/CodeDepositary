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

    rep (i, 0, n) {
        int a, b;
        cin >> a >> b;

        int ans;

        if (a > b) {
            if (a % 2) {
                ans = (a - 1) * (a - 1) + 1;
                ans += (b - 1);
            }
            else {
                ans = a * a - (b - 1);
            }
        }
        else {
            if (b % 2 == 0) {
                ans = (b - 1) * (b - 1) + 1;
                ans += (a - 1);
            }
            else {
                ans = b * b - (a - 1);
            }
        }

        cout << ans << '\n';
    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
