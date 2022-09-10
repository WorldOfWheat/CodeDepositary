#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 2e5 + 1

using namespace std;

vector<int> graph[MAX];
vector<pii> edge(MAX);
vector<bool> vis(MAX);
vector<int> deph(MAX);
vector<int> value(MAX);
queue<int> bfs;

void dfs(int x, int y) {

    for (auto i : graph[x]) {

        if (vis[i]) {
            continue;
        }

        vis[i] = true;

        dfs(i, y+1);

    }

    vis[x] = false;
    deph[x] = y;

}

void dfs2(int x) {

    for (auto i : graph[x]) {

        if (vis[i]) {
            continue;
        }

        if (deph[x] >= deph[i]) {
            continue;
        }

        vis[i] = true;
        value[i] += value[x];

        dfs2(i);

    }

    vis[x] = false;

}

void solve() {

    int n;
    cin >> n;
    rep2 (i, 1, n-1) {
        cin >> edge[i].F >> edge[i].S;
        graph[edge[i].F].pb(edge[i].S);
        graph[edge[i].S].pb(edge[i].F);
    }

    vis[1] = true;
    dfs(1, 1);
    vis[1] = false;


    int m;
    cin >> m;
    rep (i, 0, m) {

        int a, b, c;
        cin >> a >> b >> c;
        auto [f, s] = edge[b];
        if (deph[f] > deph[s]) {

            swap(f, s);
            a ^= 3;

        }
        if (a == 1) {

            value[1] += c;
            value[s] -= c;

        }
        else {

            value[s] += c;

        }
    }

    dfs2(1);

    rep2 (i, 1, n) {
        cout << value[i] << ln;
    }


}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
