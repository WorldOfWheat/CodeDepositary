#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

struct node {
    V child;
    int parent;
};

vector<node> ve;
V level;

int dfs(int x) {
    //cerr << x << sp << (ve[x].child.empty()) << ln;
    if (ve[x].child.empty()) {
        return level[x] = 0;
    }
    int maxi = 0;
    for (auto i : ve[x].child) {
        maxi = max(maxi, dfs(i)+1);
    }
    return level[x] = maxi;
}

void solve() {
    int n;
    cin >> n;
    ve.resize(n+1);
    level.resize(n+1);
    rep (i, 0, n) {
        int a;
        cin >> a;
        rep (j, 0, a) {
            int b;
            cin >> b;
            ve[i+1].child.pb(b);
            ve[b].parent = i+1;
        }
    }
    int root;
    rep2 (i, 1, n) {
        if (ve[i].parent == 0) {
            root = i;
        }
    }
    cout << root << ln;
    dfs(root);
    int ans = 0;
    rep2 (i, 1, n) {
        ans += level[i];
    }
    cout << (ans) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

///////////////////////////////////////////////////////////

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
int root;
int maxi = -INF;
V ans;

void dfs(int now) {

	for (auto i : graph[now]) {
		dfs(i);
		ans[now] = max(ans[now], ans[i] + 1);
	}

}

void solve() {

	cin >> n;	
	
	graph.resize(n+1);
	indeg.resize(n+1);
	ans.resize(n+1);

	rep2 (i, 1, n) {
		int j;
		cin >> j;
		while (j--) {
			int a;
			cin >> a;

			graph[i].push_back(a);
			indeg[a]++;
		}
	}

	rep2 (i, 1, n) {
		if (indeg[i] == 0) {
			root = i;
		}
	}

	dfs(root);

	int sum = 0;
	rep2 (i, 1, n) {
		sum += ans[i];
	}

	cout << root << ln << sum << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}