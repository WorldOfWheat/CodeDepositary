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
V dp2;

void solve() {

	int n;
	
	cin >> n;

	ve.resize(n);
	dp.resize(n+1);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	int ans = -INF;

	rep2 (i, 1, n) {
		int top = ve[i-1];
	
		if (dp2.size() && top <= dp2.back()) {
			auto it = lower_bound(dp2.begin(), dp2.end(), top);
			*it = top;
		} else {
			dp2.push_back(top);
		}

		ans = max(ans,  (int) dp2.size());
	}

	cout << (ans) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}