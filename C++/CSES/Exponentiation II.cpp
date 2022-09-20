#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define ln '\n'
#define sp " "

using namespace std;

int mod = 1e9 + 7;

int fastpow(int x, int y) {

    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return res;

}

void solve() {

    int a, b, c;
    cin >> a >> b >> c;
    mod--;
    b = fastpow(b, c);
    mod++;
    a = fastpow(a, b);
    cout << (a) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
