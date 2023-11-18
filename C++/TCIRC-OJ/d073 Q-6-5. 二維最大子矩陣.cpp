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

VV ve;
VV pf;

void solve() {
	
	int n, m;
	
	cin >> n >> m;

	ve.resize(n, V(m));
	pf.resize(n+1, V(m+1));

	rep (i, 0, n) {
		rep (j, 0, m) {
			cin >> ve[i][j];
		}
	}

	rep2 (i, 1, m) {
		rep2 (j, 1, n) {
			pf[j][i] = pf[j-1][i] + ve[j-1][i-1];
		}
	}

	int ans = -INF;
	rep2 (i, 0, n) {
		rep2 (j, i + 1, n) {
			int maxi = -INF;
			rep2 (k, 1, m) {								
				int o = pf[j][k] - pf[i][k];
				maxi = max(o, maxi + o);
				ans = max(ans, maxi);
			}			
		}
	}

	cout << (ans >= 0 ? ans : 0) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}