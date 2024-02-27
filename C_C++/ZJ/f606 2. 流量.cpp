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
#define MAX (int) 2e6 + 1

using namespace std;

vv ve(50+1, vector<int>(50+1));
vector<int> mini;

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    ve.resize(n+1);
    for (auto &i : ve) {
        i.resize(m+1);
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }

    int ans = 1e18;
    rep (i, 0, k) {
        vv ve2(50+1, vector<int>(50+1));
        rep (j, 0, n) {

            int a;
            cin >> a;
            rep (o, 0, m) {
                //cerr << (ve[j][o]) << ln;
                ve2[a][o] += ve[j][o];
            }
        }
        int sum = 0;
        rep (j, 0, m) {
            rep (o, 0, m) {
                if (j == o) {
                    sum += ve2[j][o];
                    continue;
                }
                if (ve2[j][o] <= 1000) {
                    sum += ve2[j][o] * 3;
                    continue;
                }
                sum += ve2[j][o] * 2 + 1000;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
