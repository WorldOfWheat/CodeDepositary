#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

mt19937 mt(time(0));

int fastpow(int x, int y, int mod) {
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

bool isPrime(int x) {
    srand(time(0));
    if (x <= 2) {
        return x == 2;
    }
    int r = ((mt() % ( (x - 1) - 2 + 1)) + 2);
    if (fastpow(r, x - 1, x) != 1) {
        return false;
    }
    return true;
}

void solve() {

    int n;
    cin >> n;
    cout << (isPrime(n) ? "Y" : "N") << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;

}
