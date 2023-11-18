#include <bits/stdc++.h>
#define int long long
#define VP vector<pii>
#define V vector<int>
#define VV vector<V>
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

V ve;
V vis;
VV graph;

int dfs(int x) {

	int res = ve[x];
	for (auto i : graph[x]) {
		if (vis[i]) {
			continue;
		}
		vis[i] = true;

		res += dfs(i);
	}

	return res;

}

void solve() {

	int n, m;
	cin >> n >> m;

	ve.resize(n);
	vis.resize(n);
	graph.resize(n);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = -INF;
	rep (i, 0, n) {
		if (vis[i]) {
			continue;
		}
		vis[i] = true;

		ans = max(ans, dfs(i));
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}

/////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define VP vector<pii>
#define V vector<int>
#define VV vector<V>
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

V value;
VV graph;
V vis;

int bfs(int x) {

	queue<int> qu;
	qu.push(x);

	int res = value[x];
	while (qu.size()) {
		int top = qu.front();
		qu.pop();

		for (auto i : graph[top]) {
			if (vis[i]) {
				continue;
			}
			vis[i] = true;

			res += value[i];
			
			qu.push(i);
		}
	}

	return res;

}

void solve() {

	int n, m;
	cin >> n >> m;

	value.resize(n);
	graph.resize(n);
	vis.resize(n);

	rep (i, 0, n) {
		cin >> value[i];
	}

	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = -INF;
	rep (i, 0, n) {
		if (vis[i]) {
			continue;
		}
		vis[i] = true;

		ans = max(ans, bfs(i));
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}