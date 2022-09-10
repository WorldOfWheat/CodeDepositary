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

const int M = 1e9+9;

pii operator*(pii x, pii y) {
    int a = ( (x.F * y.F % M) + (2 * x.S * y.S % M) ) % M;
    int b = ( (x.F * y.S % M) + (x.S * y.F % M) ) % M;
    return {a, b};
}

pii qpow(pii x, int y) {
    if (y == 1) {
        return x;
    }
    if (y & 1) {
        return x * qpow(x, y-1);
    }
    pii res = qpow(x, y >> 1);
    return res * res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    pii ans = qpow({a, b}, c);
    cout << (ans.F) << sp << (ans.S) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}