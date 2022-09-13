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

V ve;

void merge_sort(vector<int> &x, int l, int r) {

	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	merge_sort(x, l, mid);
	merge_sort(x, mid+1, r);

	vector<int> res(r - l + 1);
	merge(x.begin() + l, x.begin() + mid + 1, x.begin() + mid + 1, x.begin() + r + 1, res.begin());
	
	for (int i = l; i <= r; i++) {
		x[i] = res[i-l];
	}

}

void solve() {
	
	int n;
	cin >> n;
	
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}

	merge_sort(ve, 0, ve.size()-1);

	for (auto i : ve) {
		cout << i << sp;
	}
	cout << ln;

}

signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
