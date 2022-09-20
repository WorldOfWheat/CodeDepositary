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

vector<int> graph[(int) 2e5+1];
vector<bool> vis((int) 2e5+1);
vector<int> value((int) 2e5+1);
queue<int> bfs;
vector<int> path;

void solve() {

    int n, m;
    cin >> n >> m;
    rep (i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bfs.push(1);
    value[1] = 1;
    vis[1] = true;
    while (bfs.size()) {
        int top = bfs.front();
        bfs.pop();
        for (auto i : graph[top]) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            value[i] = value[top] + 1;
            bfs.push(i);
        }
    }

    if (!value[n]) {
        cout << "IMPOSSIBLE" << ln;
        return;
    }
    cout << (value[n]) << ln;

    int now = n;
    int mini = 1e18;
    path.pb(n);
    while (now != 1) {
        int temp_now = now;
        for (auto i : graph[now]) {
            if (value[i] < mini) {
                mini = value[i];
                temp_now = i;
            }
        }
        path.pb(temp_now);
        now = temp_now;
    }
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        cout << (*it) << sp;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
