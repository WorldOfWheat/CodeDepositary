#include <bits/stdc++.h>
#define int long long
#define V vector<int>
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

const V dir = {1, -1, 0, 0};
const V dir2 = {0, 0, 1, -1};
vv ve;

void solve() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    ve.resize(n);
    for (auto &i : ve) {
        i.resize(m);
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }
    rep (i, 0, p) {
        vv temp = ve;
        rep (j, 0, n) {
            rep (o, 0, m) {
                if (ve[j][o] == -1) {
                    continue;
                }
                int add = temp[j][o] / k;
                int cnt = 0;
                rep (l, 0, 4) {
                    int dx = j + dir[l];
                    int dy = o + dir2[l];
                    if (!(0 <= dx && dx < n && 0 <= dy && dy < m)) {
                        continue;
                    }
                    if (ve[dx][dy] == -1) {
                        continue;
                    }
                    cnt++;
                    ve[dx][dy] += add;
                }
                ve[j][o] -= add * cnt;
            }
        }
    }
    int maxi = -1e18, mini = 1e18;
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (ve[i][j] == -1) {
                continue;
            }
            maxi = max(maxi, ve[i][j]);
            mini = min(mini, ve[i][j]);
        }
    }
    cout << (mini) << ln << (maxi) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
