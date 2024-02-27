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

int n;
set<int> se;

void solve() {

	se.clear();

	if (n == 1) {
		cout << 1<< ln;
		return;
	}

	rep2 (i, 1, n/2) {
		if (n % i == 0) {
			se.insert(n / i);
			se.insert(i);
		}
	}

	for (auto i : se) {
		cout << i << sp;
	}
	cout << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n) solve();

	return 0;

}