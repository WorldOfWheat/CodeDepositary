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

struct node {

	int value;
	int left;
	int right;

};

int n, m;
V ve;
vector<node> tree;

int dfs(int now) {

	if (now >= n) {
		return tree[now].value;
	}

	tree[now].value = dfs(tree[now].left) + dfs(tree[now].right);

	return tree[now].value;

}

void dfs2(int now, int add_value) {

	tree[now].value += add_value;

	if (now >= n) {
		cout << now << sp;
		return;
	}

	if (tree[tree[now].left].value <= tree[tree[now].right].value) {
		dfs2(tree[now].left, add_value);
	}
	else {
		dfs2(tree[now].right, add_value);
	}

}

void solve() {

	cin >> n >> m;

	tree.resize(2*n + 1);
	ve.resize(m);

	rep (i, n, 2*n) {
		cin >> tree[i].value;
	}

	rep (i, 0, m) {
		cin >> ve[i];	
	}

	rep (i, 0, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		
		tree[a].left = b;
		tree[a].right = c;
	}

	dfs(1);

	for (auto i : ve) {
		dfs2(1, i);
	}

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}