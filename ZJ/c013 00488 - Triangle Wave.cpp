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

void solve() {
    int n, m;
    cin >> n >> m;
    rep (i, 0, m) {
        int k = 1;
        bool flag = true;
        rep2 (j, 1, 2*n) {
            //cerr << k << ln;
            rep (o, 0, k) {
                cout << k;
            }
            cout << ln;
            if (k == n) {
                flag = false;
            }
            k += (flag) ? 1 : -1;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
