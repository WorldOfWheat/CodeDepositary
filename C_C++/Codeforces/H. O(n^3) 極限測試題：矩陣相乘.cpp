#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 2e6 + 1

using namespace std;

vv ve(1, vector<int>(1));
vv ve2(1, vector<int>(1));

vv martix_mul(vv x, vv y) {

    vv res(x.size(), vector<int>(x.size()));
    rep (i, 0, x.size()) {
        rep (j, 0, x.size()) {
            int sum = 0;
            rep (o, 0, x.size()) {
                sum += x[i][o] * y[o][j];
            }
            res[i][j] = sum;
        }
    }
    return res;

}

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    ve2.resize(n);
    rep (i, 0, n) {
        ve[i].resize(n);
        string str;
        cin >> str;
        rep (j, 0, str.length()) {
            ve[i][j] = str[j] - '0';
        }
    }

    rep (i, 0, n) {
        ve2[i].resize(n);
        string str;
        cin >> str;
        rep (j, 0, str.length()) {
            ve2[i][j] = str[j] - '0';
        }
    }

    ve = martix_mul(ve, ve2);

    int ans = 0;
    rep (i, 0, n) {
        rep (j, 0, n) {
            ans ^= ve[i][j];
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
