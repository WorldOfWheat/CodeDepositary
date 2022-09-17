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

int dfs(int l, int r) {

	if (l >= r) {
		return ve[l];
	}

	int mid = (l + r) / 2;
	int res = max(dfs(l, mid), dfs(mid + 1, r));

	int l2 = mid;
	int r2 = mid;
	int now = ve[mid];

	while (l2 >= l || r2 <= r) {
		if (l2 < l) {
			now = ve[r2];
		}
		else if (r2 > r) {
			now = ve[l2];
		}
		else {
			now = max(ve[r2], ve[l2]);
		}

		while (l2 >= l && ve[l2] >= now) {
			l2--;
		}
		while (r2 <= r && ve[r2] >= now) {
			r2++;
		}

		res = max(res, now * (r2 - l2 - 1)); // -1的原因是不含r2 l2，所以全文是 + 1 - 2
	}

	return res;

}

void solve() {
	
	int n;
	cin >> n;

	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}

	cout << (dfs(0, n - 1)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
