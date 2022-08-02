#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second
#define cal(x) ( x * (x + 5) )
#define mod ((int) (1e9) + 7)

using namespace std;
__attribute__((optimize("-O3")))

int n, m;

int fastpow(int x, int y) {
    int sum = 1;
    while (y > 0) {
        if (y & 1) {
            sum *= x;
            sum %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return sum;
}

void solve() {

    cin >> n >> m;
    cout << (fastpow(n, m)) << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
