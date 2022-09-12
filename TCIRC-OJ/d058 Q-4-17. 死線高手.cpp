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

bool cmp(pii x, pii y) {
	return (x.S < y.S);
}

void solve() {

	int n;
	cin >> n;
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i].F;
	}
	rep (i, 0, n) {
		cin >> ve[i].S;
	}

	sort(ve.begin(), ve.end(), cmp);

	int now = 0;
	rep (i, 0, n) {
		now += ve[i].F;
		if (now > ve[i].S) {
			cout << "no" << ln;
			return;
		}
	}

	cout << "yes" << ln;

}

signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) solve();

	return 0;

}
