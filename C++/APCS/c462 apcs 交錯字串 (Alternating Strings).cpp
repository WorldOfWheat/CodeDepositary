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
V ve;

void solve() {

    cin >> n;

    string str;
    cin >> str;

    int cont = 1;
    rep (i, 1, str.length()) {
        auto top = str[i];
        if (isupper(top) == isupper(str[i - 1])) {
            cont++;
        }
        else {
            ve.push_back(cont);
            cont = 1;
        }
    }
    ve.push_back(cont);

    int ans = -INF;
    int now = 0;
    rep (i, 0, ve.size()) {
        if (ve[i] > n) {
            ans = max(ans, now + n);
            now = n;
        }
        if (ve[i] == n) {
            now += n;
            ans = max(ans, now);
        }
        if (ve[i] < n) {
            now = 0;
        }
    }

    cout << (ans < 0 ? 0 : ans) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
