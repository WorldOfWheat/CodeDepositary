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

map<int, int> ma;

void solve() {

	int n;
	cin >> n;
	rep (i, 0, n) {
		int a, b, c;
		cin >> a >> b >> c;
		ma[b] += a;
		ma[c+1] -= a;
	}
	
	int ans = 0;
	int now = 0;
	for (auto i : ma) {
		now += i.S;
		ans = max(ans, now);
	}

	cout << ans << ln;

}

signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
