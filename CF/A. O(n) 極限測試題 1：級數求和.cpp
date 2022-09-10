#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define lll __int128
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

const lll mod = ((lll) 1 << 64);

lll read() {

    char in;
    bool flag = false;
    lll res = 0;
    while (in = getchar(), in >= '0' && in <= '9') {
        res *= 10;
        res += in - '0';
    }

    return res;

}

void print(lll x) {

    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');

}

void solve() {

    lll a = read();
    lll b = read();
    lll ans = (a + b) * (b - a + 1) / 2;
    ans %= mod;
    print(ans);
    cout << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
