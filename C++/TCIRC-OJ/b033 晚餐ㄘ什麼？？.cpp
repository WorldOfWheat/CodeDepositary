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

map<string, int> ma;
map<string, int> ma2;

void solve() {

	int n, m;

	cin >> n >> m;

	rep (i, 0, n) {
		string a;
		cin >> a;

		ma[a]++;
	}

	rep (i, 0, m) {
		string a;
		cin >> a;

		ma2[a]++;
	}

	stringstream ss;
	int cnt = 0;

	for (auto i : ma) {
		if (ma2[i.F]) {
			cnt++;
			ss << (i.F) << ln;
		}
	}

	cout << (cnt) << ln << (ss.str());

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}