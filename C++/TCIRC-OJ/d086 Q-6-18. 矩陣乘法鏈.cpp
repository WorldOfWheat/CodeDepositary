#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define VV vector<vector<int>>
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
VV dp;

int dfs(int l, int r) {

	if (l + 1 >= r) {
		return 0;
	}

	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	int res = INF;

	rep (i, l+1, r) {
		int sum = dfs(l, i) + dfs(i, r);
		sum += ve[l] * ve[i] * ve[r];

		res = min(res, sum);
	}

	return dp[l][r] = res;

}

void solve() {

	int n;

	cin >> n;

	n++;

	ve.resize(n);
	dp.resize(n+1, V(n+1, -1));

	rep (i, 0, n) {
		cin >> ve[i];
	}

	cout << (dfs(0, n - 1)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}