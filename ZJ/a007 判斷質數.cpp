#include <bits/stdc++.h>a
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

int n;

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
    for (int i = 0; i < 20; i++) {
        int r = ((rand() % ( (x - 1) - 2 + 1)) + 2);
        if (fastpow(r, x - 1, x) != 1) {
            return false;
        }
    }
    return true;
}

void solve() {

    cout << (isPrime(n) ? "質數" : "非質數") << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;

}
