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
V weight;
VV graph;
V cnt;
int maxi = -INF;

void dfs(int parent, int now) {

	maxi = max(maxi, cnt[weight[now]]);

	for (auto i : graph[now]) {
		if (i == parent) {
			continue;
		}

		cnt[weight[i]]++;
		dfs(now, i);
		cnt[weight[i]]--;
	}

}

void solve() {

	cin >> n;

	weight.resize(n);
	graph.resize(n);
	cnt.resize(n);

	rep (i, 0, n) {
		cin >> weight[i];
	}

	V temp(weight);
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (auto &i : weight) {
		i = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
	}

	rep (i, 0, n - 1) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cnt[weight[0]]++;
	dfs(-1, 0);

	cout << (maxi) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}