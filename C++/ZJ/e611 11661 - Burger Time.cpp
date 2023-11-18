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

int n;
set<int> se;
set<int> se2;

void solve() {
	se.clear();
	se2.clear();

	string str;
	cin >> str;

	rep (i, 0, n) {
		if (str[i] == 'Z') {
			cout << 0 << ln;
			return;
		}
		if (str[i] == '.') {
			continue;
		}
		if (str[i] == 'R') {
			se.insert(i);
			continue;
			continue;
		}
		se2.insert(i);
	}
	
	int ans = 1e18;
	for (auto i : se) {
		auto it = se2.upper_bound(i);
		if (it == se2.end()) {
			continue;
		}
		ans = min((*it) - i, ans);
	}
	for (auto i : se2) {
		auto it = se.upper_bound(i);
		if (it == se.end()) {
			continue;
		}
		ans = min((*it) - i, ans);
	}

	cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) solve();

    return 0;
}
