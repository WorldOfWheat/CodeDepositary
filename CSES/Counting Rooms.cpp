#include <bits/stdc++.h>
#define int long long
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

bool visited[1000+1][1000+1];
queue<pii> bfs;
int dir_ud[4] = {1, -1, 0, 0};
int dir_lr[4] = {0, 0, -1, 1};

void solve() {

    int n, m;
    cin >> n >> m;
    rep (i, 0, n) {
        rep (j, 0, m) {
            char a;
            cin >> a;
            visited[i][j] = (a == '#');
        }
    }

    int ans = 0;
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (!visited[i][j]) {
                ans++;
                bfs.push({i, j});
                while (bfs.size()) {
                    pii top = bfs.front();
                    bfs.pop();
                    rep (k, 0, 4) {
                        int dx = top.F + dir_ud[k];
                        int dy = top.S + dir_lr[k];
                        if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                            continue;
                        }
                        if (visited[dx][dy]) {
                            continue;
                        }
                        visited[dx][dy] = true;
                        bfs.push({dx, dy});
                    }
                }
            }
        }
    }
    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
