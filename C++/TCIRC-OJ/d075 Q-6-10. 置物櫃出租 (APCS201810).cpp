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

void solve() {

	int n, m, k;
	cin >> n >> m >> k;
	
	int re = m - k;

	ve.resize(n);
	dp.resize(n+1, V(re+1));

	int sum = 0;

	rep (i, 0, n) {
		cin >> ve[i];
		sum += ve[i];
	}

	rep2 (i, 1, n) {
		int top = ve[i-1];
		rep2 (j, 1, re) {
			if (j < top) {
				dp[i][j] = dp[i-1][j];
				continue;
			}

			dp[i][j] = max(dp[i-1][j], dp[i-1][j - top] + top);
		}
	}

	cout << (sum - dp[n][re]) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}