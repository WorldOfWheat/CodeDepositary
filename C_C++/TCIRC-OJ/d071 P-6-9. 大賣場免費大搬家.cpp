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
V dp;

void solve() {

	int n, m;
	
	cin >> n >> m;

	ve.resize(n);
	dp.resize(m+1);
	
	rep (i, 0, n) {
		cin >> ve[i].F;
	}
	rep (i, 0, n) {
		cin >> ve[i].S;
	}

	rep2 (i, 1, n) {
		pii top = ve[i-1];

		rrep (j, m, 1) {
			if (j < top.F) {
				continue;
			}

			dp[j] = max(dp[j], dp[j - top.F] + top.S) ;
		}
	}

	cout << (dp[m]) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}