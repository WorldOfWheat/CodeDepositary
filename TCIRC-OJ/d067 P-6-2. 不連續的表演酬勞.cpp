#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define vv vector<vector<int>>
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
V dp;

void solve() {
	
    int n;
	cin >> n;
	
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}

	dp.resize(n+1);
	dp[1] = ve[0];

	rep2 (i, 2, n) {
		dp[i] = max(dp[i-1], dp[i-2] + ve[i-1]);
	}

	cout << (dp[n]) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}