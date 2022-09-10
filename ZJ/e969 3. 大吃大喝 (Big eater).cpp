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

const V items = {32, 55};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n < items[k]) {
		cout << "Wayne can't eat and drink." << ln;
	}
	int now = 0;
	while (true) {
		if (n - items[k] < 0) {
			return;
		}
		cout << now << ": ";
		now += m;
		n -= items[k];
		if (k) {
			if (n == 0) {
				cout << "Wayne drinks a Corn soup, and now he doesn't have money." << ln;
				return;
			}
			cout << "Wayne drinks a Corn soup, and now he has " << n << " dollar" << (n == 1 ? "" : "s") << "." << ln;
		}
		else {
			if (n == 0) {
				cout << "Wayne eats an Apple pie, and now he doesn't have money." << ln;
				return;
			}
			cout << "Wayne eats an Apple pie, and now he has " << n << " dollar" << (n == 1 ? "" : "s") << "." << ln;
		}
		k = 1 - k;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
