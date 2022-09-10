#include <bits/stdc++.h>
#define int long long
#define V vector<int>
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

using namespace std;

vector<pii> ve;

void solve() {
	int n;
	cin >> n;
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i].F >> ve[i].S;
	}
	sort(ve.begin(), ve.end());
	int ans = 0;
	pii last = {0, 0};
	rep (i, 0, n) {
		if (ve[i].S >= last.S) {
			ans += ve[i].S - max(ve[i].F, last.S);
		}
		last.S = max(last.S, ve[i].S);
	}
	cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
