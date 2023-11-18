#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
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
V path;
bitset<50000 + 5> vis;

void dfs(int x, int y) {

	path.push_back(y);

	for (auto i : graph[y]) {
		if (x == i) {
			continue;
		}

		dfs(y, i);
		path.push_back(y);
	}

}

void solve() {

	cin >> n;

	graph.resize(n);

	int sum = 0;
	rep (i, 0, n-1) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back(b);
		graph[b].push_back(a);

		sum += c;
	}

	rep (i, 0, n) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(-1, 0);

	cout << (sum * 2) << ln;
	for (auto i : path) {
		cout << i << sp;
	}
	cout << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}