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
VP graph;
V outdeg;
V cnt;
int ans, sum;

void bfs() {

	queue<int> qu;
	
	rep (i, 0, n) {
		if (outdeg[i] == 0) {
			qu.push(i);
		}
	}

	bool flag = true;

	while (qu.size()) {
		int top = qu.front();
		qu.pop();

		cnt[top]++;

		if (flag && cnt[top] >= n / 2) {
			flag = false;
			ans = top;
		}
		
		sum += min(cnt[top], n - cnt[top]) * graph[top].S;

		if (graph[top].F == -1) {
			break;
		}
		cnt[graph[top].F] += cnt[top];

		outdeg[graph[top].F]--;
		if (outdeg[graph[top].F] == 0) {
			qu.push(graph[top].F);
		}
	}

}

void solve() {

	cin >> n;

	graph.resize(n);
	outdeg.resize(n);
	cnt.resize(n);

	rep (i, 0, n-1) {
		int a, b;
		cin >> a >> b;

		graph[i+1] = {a, b};
		outdeg[a]++;
	}
	graph[0] = {-1, 0};

	bfs();

	cout << ans << ln << sum << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}

//////////////////////////////////////////////////////////

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
VVP graph;
V cnt;
int ans, sum;
bool flag = true;

void dfs(int now) {

	for (auto i : graph[now]) {
		int top = i.F;
		dfs(top);
		sum += min(cnt[top], n - cnt[top]) * i.S;
		cnt[now] += cnt[top];
	}

	cnt[now]++;
	if (cnt[now] >= n / 2 && flag) {
		ans = now;
		flag = false;
	}

}

void solve() {

	cin >> n;

	graph.resize(n);
	cnt.resize(n);

	rep (i, 0, n-1) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back({i+1, b});
	}

	dfs(0);

	cout << ans << ln << sum << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}