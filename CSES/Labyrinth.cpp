
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

const int dir_x[4] = {1, -1, 0, 0};
const int dir_y[4] = {0, 0, 1, -1};
const char dir[4] = {'U', 'D', 'L', 'R'};
bool visited[1000+1][1000+1];
int value[1000+1][1000+1];
queue<pii> bfs;

void solve() {

    int n, m;
    pii start;
    pii _end;
    cin >> n >> m;
    rep (i, 0, n) {
        rep (j, 0, m) {
            char a;
            cin >> a;
            if (a == 'A') {
                start.F = i;
                start.S = j;
            }
            if (a == 'B') {
                _end.F = i;
                _end.S = j;
            }
            if (a == '#') {
                visited[i][j] = true;
            }
        }
    }
    bfs.push(start);
    while (bfs.size()) {
        pii top = bfs.front();
        bfs.pop();
        if (top.F == _end.F && top.S == _end.S) {
            break;
        }
        rep (i, 0, 4) {
            int dx = top.F + dir_x[i];
            int dy = top.S + dir_y[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }
            if (visited[dx][dy]) {
                continue;
            }
            visited[dx][dy] = true;
            value[dx][dy] = value[top.F][top.S] + 1;
            bfs.push({dx, dy});
        }
    }
    if (value[_end.F][_end.S] == 0) {
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;
    cout << (value[_end.F][_end.S]) << ln;

    stringstream ss;
    int now_x = _end.F, now_y = _end.S;
    int mini = 1e18;
    value[start.F][start.S] = -1;
    while (now_x != start.F || now_y != start.S) {
        char path;
        int temp_x = now_x;
        int temp_y = now_y;
        rep (i, 0, 4) {
            int dx = now_x + dir_x[i];
            int dy = now_y + dir_y[i];
            if (0 <= dx && dx < n && 0 <= dy && dy < m) {
                if (value[dx][dy] != 0 && value[dx][dy] <= mini) {
                    mini = value[dx][dy];
                    path = dir[i];
                    temp_x = dx;
                    temp_y = dy;
                }
            }
        }
        now_x = temp_x;
        now_y = temp_y;
        ss << path;
    }
    string str = ss.str();
    for (auto it = str.rbegin(); it != str.rend(); it++) {
        cout << (*it);
    }
    cout << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
