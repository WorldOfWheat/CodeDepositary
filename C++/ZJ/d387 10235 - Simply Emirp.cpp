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
    rep (i, 0, 20) {
        int r = (rand() % ((x - 1) - 2 + 1)) + 2;
        if (fastpow(r, x - 1, x) != 1) {
            return false;
        }
    }
    return true;
}

void solve() {

    bool flag = isPrime(n);

    if (!flag) {
        cout << n << " is not prime." << ln;
        return;
    }

    string str = to_string(n);
    reverse(str.begin(), str.end());

    int temp = atoi(str.c_str());

    if (temp == n) {
        cout << n << " is prime." << ln;
        return;
    }

    bool flag2 = isPrime(temp);

    if (flag && flag2) {
        cout << n << " is emirp." << ln;
    } else {
        cout << n << " is prime." << ln;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;

}
