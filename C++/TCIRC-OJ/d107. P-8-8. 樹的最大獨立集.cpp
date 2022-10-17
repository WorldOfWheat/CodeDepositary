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
V parent;
V outdeg;
V vis;
int res;

void bfs() {

	queue<int> qu;
	rep (i, 0, n) {
		if (outdeg[i] == 0) {
			qu.push(i);
		}
	}

	while (qu.size()) {
		int top = qu.front();
		qu.pop();

		if (top == 0) {
			break;
		}

		if (!vis[top]) {
			res++;
			vis[parent[top]] = true;
		}

		outdeg[parent[top]]--;
		if (outdeg[parent[top]] == 0) {
			qu.push(parent[top]);
		}
	}

}

void solve() {

	cin >> n;

	parent.resize(n);
	outdeg.resize(n);
	vis.resize(n);

	rep (i, 1, n) {
		cin >> parent[i];
		outdeg[parent[i]]++;
	}

	bfs();

	cout << (res + (!vis[0])) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}