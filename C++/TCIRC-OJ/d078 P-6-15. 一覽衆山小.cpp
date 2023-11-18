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
V dp;

void solve() {

	int n;

	cin >> n;

	ve.resize(n);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	int ans = -INF;

	dp.push_back(ve[0]);

	rep (i, 1, n) {
		if (ve[i] > dp.back()) {
			dp.push_back(ve[i]);
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), ve[i]);
			*it = ve[i];
		}

		ans = max(ans, (int) dp.size());
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}