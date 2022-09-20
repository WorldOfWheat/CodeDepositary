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

VP ve;
VV dp;

void solve() {

	int n, m;
	cin >> n >> m;

	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i].F >> ve[i].S;
	}

	dp.resize(n+1, V(2));
	dp[1][0] = abs(ve[0].F - m);
	dp[1][1] = abs(ve[0].S - m);

	rep2 (i, 2, n) {
		pii top = ve[i-1];
		pii top2 = ve[i-2];
		dp[i][0] = min(abs(top.F - top2.F) + dp[i-1][0], abs(top.F - top2.S) + dp[i-1][1]);
		dp[i][1] = min(abs(top.S - top2.F) + dp[i-1][0], abs(top.S - top2.S) + dp[i-1][1]);
	}

	cout << (min(dp[n][0], dp[n][1])) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}