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

bitset<25> bs;
V ve;

void solve() {
	int n;
	cin >> n;
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
		if (ve[i] == 9) {
			bs[i] = 1;
			if (i - 1 >= 0) {
				bs[i-1] = 1;
			}
			if (i + 1 != n) {
				bs[i+1] = 1;
			}
		}
		if (ve[i] == 1) {
			bs[i] = 1;
		}
	}
	rep (i, 0, n) {
		if (ve[i] == 1) {
			break;
		}
		bs[i] = 1;
	}
	rrep (i, n-1, 0) {
		if (ve[i] == 1) {
			break;
		}
		bs[i] = 1;
	}
	cout << (n - bs.count()) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
