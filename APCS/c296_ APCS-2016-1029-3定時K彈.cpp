#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n, m, k;

void solve() {

    int ans = 0;
    for (int i = n - k + 1; i <= n; i++) {
        ans = (ans + m) % i;
    }
    cout << (ans + 1) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m >> k) solve();

    return 0;
}
