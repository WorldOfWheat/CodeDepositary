#include <bits/stdc++.h>
#define int long long
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define sp " "
#define ln "\n"

using namespace std;

void solve() {

    int n;
    cin >> n;
    int ans = 0;
    rep (i, 0, n) {
        int a, b;
        cin >> a >> b;
        ans += (a * b);
    }
    cout << ans << ln;

}

signed main() {

    solve();

    return 0;

}

