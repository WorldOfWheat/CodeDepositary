#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
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
#define MN (int) 1e18

using namespace std;

VP ve;
multimap<int, int> mma;

void solve() {

	int n;
	cin >> n;
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i].F >> ve[i].S;
	}

	sort(ve.begin(), ve.end());

	int ans = MN;
	rep (i, 0, n) {
		pii top = ve[i];
		auto it = mma.lower_bound(top.S - ans);
		while (it != mma.end() && it->F <= top.S + ans) {
			if (it->S < top.F - ans) {
				it = mma.erase(it);
				continue;
			}
			ans = min(ans, abs(top.F - it->S) + abs(top.S - it->F));
			it++;
		}
		mma.insert({top.S, top.F});
	}

	cout << ans << ln;

}

signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
