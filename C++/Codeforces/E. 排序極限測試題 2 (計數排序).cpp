#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 2e5 + 1

using namespace std;

vector<int> ve(9+1);

void solve() {

    int n;
    cin >> n;
    rep (i, 0, n) {
        int a;
        cin >> a;
        ve[a]++;
    }
    rep2 (i, 0, 9) {
        if (ve[i] != 0) {
            rep (j, 0, ve[i]) {
                cout << i << sp;
            }
        }
        cout << ln;
    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
