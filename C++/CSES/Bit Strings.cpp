#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n;

void solve() {

    cin >> n;
    int ans = 1;
    while (n--) {
        ans *= 2;
        ans %= ((int) 1e9 + 7);
    }
    cout << (ans) << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
