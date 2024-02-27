#include <bits/stdc++.h>
#define int long long
#define VP vector<pii>
#define V vector<int>
#define VV vector<V>
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
int len;
V ve;
VV dp;
VV dp2;

int dfs(int x, int y) {

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	if (x == 0) {
		return 1;
	}

	int res = 0;
	rep2 (i, y, 9) {
		res += dfs(x-1, i);
	}

	return dp[x][y] = res;

}

int dfs2(int x, int y) {

	if (dp2[x][y] != -1) {
		return dp2[x][y];
	}

	if (x == 0) {
		return 0;
	}

	int res = 0;
	rep (i, y, ve[x-1]) {
		res += dfs(x-1, i);
	}
	if (ve[x-1] >= y) {
		res += dfs2(x - 1, ve[x-1]);
	}

	return (dp2[x][y] = res);

}

void solve() {

	ve.clear();

	while (n > 0) {
		ve.push_back(n % 10);
		n /= 10;
	}

	len = ve.size();

	dp.resize(len + 1, V(9+1, -1));
	dp2.resize(len + 1, V(9+1, -1));

	int ans = 0;
	rep (i, 0, ve.back()) {
		ans += dfs(len-1, i);
	}
	ans += dfs2(len-1, ve.back());

	cout << (ans - 1) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n) solve();

	return 0;
	
}

////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define VP vector<pii>
#define V vector<int>
#define VV vector<V>
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

V ve;
VV dp;

void solve() {

	string str;
	cin >> str;

	for (auto i : str) {
		ve.push_back(i - '0');
	}

	dp.resize(str.length() + 1, V(9 + 1));

	rep2 (i, 1, 9) {
		dp[1][i] = 1;
	}

	rep2 (i, 2, str.length()) {
		dp[i][9] = dp[i-1][9];
		rrep (j, 8, 0) {
			dp[i][j] = dp[i][j+1] + dp[i-1][j];
		}
	}

	int ans = 0;
	rep (i, 0, ve[0]) {
		ans += dp[str.length()][i];
	}
	ans++;
	rep (i, 1, str.length()) {
		if (ve[i] < ve[i-1]) {
			ans--;
			break;
		}

		rep (j, ve[i-1], ve[i]) {
			ans += dp[str.length() - i][j];
		}
	}

	cout << (ans) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}