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

void solve() {

    int n;
    cin >> n;
    int sum = 0;
    int num = 1;
    int pos;
    rep (i, 0, n) {
        num *= 10;
        sum += (num / 17);
        pos = (num / 17);
        num %= 17;
    }
    cout << (pos) << sp << (sum) << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;

}
