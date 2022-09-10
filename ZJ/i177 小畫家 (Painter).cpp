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

using namespace std;

const vector<int> dir_x = {1, -1, 0, 0};
const vector<int> dir_y = {0, 0, 1, -1};
vv ve(1, vector<int>(1));
queue<pii> bfs;
vv vis(1, vector<int>(1));

void solve() {

    int n, m, s1, s2, k;
    cin >> n >> m >> s1 >> s2 >> k;
    s1--;
    s2--;
    ve.resize(n);
    rep (i, 0, n) {
        ve[i].resize(m);
    }
    vis = ve;
    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }
    bfs.push({s1, s2});
    vis[s1][s2] = 1;
    int pos = ve[s1][s2];
    ve[s1][s2] = k;
    int now_x = s2, now_y = s1;
    while (bfs.size()) {
        pii top = bfs.front();
        //cerr << (top.F) << sp << (top.S) << ln;
        bfs.pop();
        rep (i, 0, 4) {
            int dx = top.F + dir_x[i];
            int dy = top.S + dir_y[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }
            if (vis[dx][dy]) {
                continue;
            }
            if (ve[dx][dy] != pos) {
                continue;
            }
            ve[dx][dy] = k;
            vis[dx][dy] = 1;
            bfs.push({dx, dy});
        }
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            cout << ve[i][j] << sp;
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
