#include <bits/stdc++.h>
#define int long long
#define sp " "
#define ln "\n"

using namespace std;

void solve() {

    int n;
    cin >> n;
    if ( n <= 10 ) {
        cout << (n * 100) << ln;
        return;
    }
    if (11 <= n && n <= 20) {
        n -= 10;
        cout << (n * 200 + 1000) << ln;
        return;
    }
    if (21 <= n) {
        n -= 20;
        cout << (n * 300 + 3000) << ln;
    }

}

signed main() {

    solve();

    return 0;

}

