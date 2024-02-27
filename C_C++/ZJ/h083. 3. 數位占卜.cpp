#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
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
set<string> se;

void solve() {

    cin >> n;
    rep (i, 0, n) {
        string str;
        cin >> str;

        se.insert(str);
    }

    int ans = 0;
    for (auto i : se) {
        int len = i.length();

        if (len <= 2) {
            continue;
        }
        rep2 (j, 1, len / 2) {
            if (i.substr(0, j) == i.substr(len - j)) {
                ans += se.count(i.substr(j, len - 2 * j));
            }
        }
    }

    cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
