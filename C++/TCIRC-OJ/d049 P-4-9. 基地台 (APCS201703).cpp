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

int n, m;
V ve;

bool check(int x) {
	int now = 0;
	int cnt = 0;
	while (true) {
		int k = ve[now] + x;
		auto it = upper_bound(ve.begin(), ve.end(), k);
		cnt++;
		if (it == ve.end()) {
			break;
		}
		now = distance(ve.begin(), it);
	}
	return cnt <= m;
}

int _bsearch(int l, int r) {
	//cerr << (l) << sp << r << ln;
	if (l > r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if (check(mid)) {
		return _bsearch(l, mid-1);
	}
	else {
		return _bsearch(mid + 1, r);
	}
}

void solve() {
	cin >> n >> m;
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}
	sort(ve.begin(), ve.end());
	cout << (_bsearch(1, 1e18)) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
