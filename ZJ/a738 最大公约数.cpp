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

int _gcd(int x, int y) {
	if (y > x) {
		return gcd(y, x);
	}
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

void solve() {
	cout << (_gcd(n, m)) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) solve();
    return 0;
}
