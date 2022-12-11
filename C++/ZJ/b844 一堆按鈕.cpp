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
#define sp " "
#define ln "\n"
#define INF (int) 1e18

using namespace std;

int n, m;
V ve;
V ve2;


void solve() {

    while (cin >> n >> m) {
        ve.resize(n);

        rep (i, 0, n) {
            cin >> ve[i];
        }

        sort(ve.begin(), ve.end());

        rep (i, 0, m) {
            int a;
            cin >> a;

            auto it = upper_bound(ve.begin(), ve.end(), a);
            cout << (distance(ve.begin(), it) % 2) << ln;
        }
    } 
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
