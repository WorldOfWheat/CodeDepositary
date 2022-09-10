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

int n;
vv ve;
bitset<100+1> bsx;
bitset<100+1> bsy;

void solve() {
    bsx.reset();
    bsy.reset();
    ve.resize(n);
    for (auto &i : ve) {
        i.resize(n);
    }
    rep (i, 0, n) {
        rep (j, 0, n) {
            cin >> ve[i][j];
        }
    }
    rep (i, 0, n) {
        int sum = 0;
        int sum2 = 0;
        rep (j, 0, n) {
            sum += ve[j][i];
            sum2 += ve[i][j];
        }
        bsx[i] = sum & 1;
        bsy[i] = sum2 & 1;
    }
    int cnt = bsx.count();
    int cnt2 = bsy.count();
    if (cnt == 0 && cnt2 == 0) {
        cout << "OK" << ln;
        return;
    }
    if (cnt >= 2 || cnt2 >= 2) {
        cout << "Corrupt" << ln;
        return;
    }
    int dx, dy;
    rep (i, 0, n) {
        if (bsx[i]) {
            dx = i+1;
        }
        if (bsy[i]) {
            dy = i+1;
        }
    }
    cout << "Change bit (" << dy << "," << dx << ")" << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
