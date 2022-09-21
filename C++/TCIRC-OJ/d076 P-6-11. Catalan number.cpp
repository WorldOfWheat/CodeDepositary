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
#define MOD (int) 1e9 + 9

using namespace std;

V table(100+1);

int dfs(int x) {

	if (table[x] != 0) {
		return table[x];
	}

	int res = 0;
	rep (i, 0, x) {
		res += dfs(i) * dfs(x - 1 - i);
		res %= MOD;
	}

	return table[x] = res;

}

void solve() {

	int n;
	cin >> n;

	table[0] = 1;
	
	cout << (dfs(n)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}

///////////////////////////////////////////////////////////////////////////////////////////////

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
#define MOD (int) 1e9 + 9

using namespace std;

V dp;

void solve() {

	int n;
	cin >> n;

	dp.resize(n+1);
	dp[0] = 1;

	rep2 (i, 1, n) {
		rep (j, 0, i) {
			dp[i] += dp[j] * dp[i-1-j];
			dp[i] %= MOD;
		}
	}

	cout << dp[n] << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}