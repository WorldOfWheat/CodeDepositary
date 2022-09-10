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
#define MAXN (LONG_LONG_MAX - 1)

using namespace std;

void solve() {
	
	int n;
	cin >> n;

	int ans = 0;
	int mini = MAXN;
	rep (i, 0, n) {
		int in;
		cin >> in;
		ans = max(ans, in - mini);
		mini = min(mini, in);
	}

	cout << ans << ln;

}

signed main() {
    
	ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
