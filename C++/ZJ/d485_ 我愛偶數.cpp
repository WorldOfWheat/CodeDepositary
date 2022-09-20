#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n, m;

void solve() {

    cin >> n >> m;
    cout << ((m - n + 1 + !((bool) (m % 2))) >> 1) << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
