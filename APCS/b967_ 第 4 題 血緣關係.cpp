#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
#define rep(x, y) for (int x = 0; x < y; x++)
#define pb push_back

using namespace std;

int n;
vector<int> graph[(int) 1e5+1];
vector<int> vis;
int maxi = -1e18;
int maxi_pos;

void dfs(int x, int y) {
    if (y > maxi) {
        maxi = y;
        maxi_pos = x;
    }
    vis[x] = 1;
    for (auto a : graph[x]) {
        if (vis[a]) {
            continue;
        }
        dfs(a, y+1);
    }
}

void solve() {

    vis.resize(n+1);
    rep(i, n) {
        graph[i].clear();
    }

    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    fill(vis.begin(), vis.end(), 0);
    maxi = -1e18;
    dfs(0, 0);

    fill(vis.begin(), vis.end(), 0);
    maxi = -1e18;
    dfs(maxi_pos, 0);

    cout << maxi << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
