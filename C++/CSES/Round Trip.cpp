#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
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

vector<int> graph[(int) 1e5 + 1];
vector<int> vis((int) 1e5 + 1);

void dfs(int x, int y) {

    for (auto i : graph[x]) {
        if (i == y) {
            continue;
        }
        if (vis[i]) {
            vector<int> ans;
            ans.pb(x);
            while (ans.back() != i) {
                ans.pb(vis[ans.back()]);
            }
            cout << (ans.size() + 1) << ln;
            for (auto j : ans) {
                cout << j << sp;
            }
            cout << x << ln;
            exit(0);
        }
        vis[i] = x;
        dfs(i, x);
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
        if (vis[i]) {
            continue;
        }
        vis[i] = i;
        dfs(i, 0);
    }
    cout << ("IMPOSSIBLE") << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
