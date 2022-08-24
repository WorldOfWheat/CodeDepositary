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
bool vis[(int) 2e5+1];
int color[(int) 2e5+1];

void dfs(int x, int y) {
    for (auto i : graph[x]) {
        if (color[i] == y) {
            cout << "IMPOSSIBLE" << ln;
            exit(0);
        }
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        color[i] = 3 - y;
        dfs(i, 3 - y);
    }
}

void solve() {

    int n, m;
    cin >> n >> m;
    rep (i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    rep2 (i, 1, n) {
        if (!color[i]) {
            color[i] = 1;
            dfs(i, 1);
        }
    }
    rep2 (i, 1, n) {
        cout << (color[i]) << sp;
    }
    cout << ln;
	
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
