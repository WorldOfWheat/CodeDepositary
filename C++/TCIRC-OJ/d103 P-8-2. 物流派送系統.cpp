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
vector<vector<pii>> graph;
int maxi_weight = -INF;
int maxi_depth = -INF;

void dfs(int parent, int now, int sum_depth, int sum_weight) {

	//cerr << ("#") << now << ln;

	maxi_weight = max(maxi_weight, sum_weight);
	maxi_depth = max(maxi_depth, sum_depth);

	for (auto i : graph[now]) {
		int top = i.F;

		if (top == parent) {
			continue;
		}

		dfs(now, top, sum_depth + 1, sum_weight + i.S);
	}

}

void solve() {

	cin >> n;

	graph.resize(n);

	rep (i, 0, n-1) {
		int a, b;
		cin >> a >> b;

		graph[i+1].push_back({a, b});
		graph[a].push_back({i+1, b});
	}	

	dfs(-1, 0, 0, 0);

	cout << (maxi_weight) << ln << (maxi_depth) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}