#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;
map<int, int> ma;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(m);
    rep (i, 0, m) {
        cin >> ve[i];
    }
    int l = 0;
    int ans = 0;
    rep (r, 0, m) {
        int top = ve[r];
        ma[top]++;
        while (ma[top] > 1) {
            ma[ve[l]]--;
            l++;
        }
        ans += ((r - l + 1) == n);
    }
    cout << (ans) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define vv vector<vector<int>>
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
map<int, int> ma;

void solve() {

	int n, m;
	cin >> n >> m;

	ve.resize(m);
	rep (i, 0, m) {
		cin >> ve[i];
	}

	int ans = 0;
	int cnt = 0;
	int l = 0;
	rep (i, 0, m) {
		int top = ve[i];
		cnt += ma[top] == 0;
		ma[top]++;
		while (ma[top] > 1) {
			int top2 = ve[l];
			ma[top2]--;
			cnt -= ma[top2] == 0;
			l++;
		}
		ans += cnt == n;
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
