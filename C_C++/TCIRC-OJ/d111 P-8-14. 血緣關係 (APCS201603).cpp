#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

int n;
VV graph;
V indeg;
V depth;
int ans;

void dfs(int now) {

    for (auto i : graph[now]) {
        dfs(i);

        ans = max(ans, depth[now] + depth[i] + 1);
        depth[now] = max(depth[now], depth[i] + 1);
    }

}

void solve() {

    cin >> n;

    graph.resize(n);
    indeg.resize(n);
    depth.resize(n);

    rep2 (i, 1, n - 1) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        indeg[b]++;
    }

    int root;
    rep (i, 0, n) {
        if (indeg[i] == 0) {
            root = i;
        }
    }

    dfs(root);

    cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
