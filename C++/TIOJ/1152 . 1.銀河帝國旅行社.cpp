#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<int> graph[(int) 1e5+1];
vector<int> vis;
int maxi = -1e18;
int maxi_pos;

void dfs(int x, int y) {
    vis[x] = 1;
    if (y > maxi) {
        maxi_pos = x;
        maxi = y;
    }
    for (auto a : graph[x]) {
        if (vis[a]) {
            continue;
        }
        dfs(a, y+1);
    }

}

void solve() {

    cin >> n;
    vis.resize(n+1);
    for (int i = 0; i < n; i++) {
        int a;
        while (cin >> a, a != -1) {
            graph[a].pb(i);
            graph[i].pb(a);
        }
    }
    dfs(0, 0);

    maxi = -1e18;
    fill(vis.begin(), vis.end(), 0);

    dfs(maxi_pos, 0);
    cout << (maxi) << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
