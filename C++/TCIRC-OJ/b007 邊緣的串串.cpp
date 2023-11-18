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

int n, m;

int binarySearch(int l, int r) {

	if (l > r) {
		return l;
	}

	int mid = (l + r) / 2;

	if (m * mid > n) {
		return binarySearch(l, mid-1);
	}
	else {
		return binarySearch(mid+1, r);
	}

}

void solve() {

	cin >> n >> m;

	cout << (n - ((binarySearch(1, INF)-1) * m)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}