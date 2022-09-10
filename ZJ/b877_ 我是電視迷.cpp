#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m;

void solve() {

    cin >> n >> m;
    if (n > m) {
        cout << ((m + 100) - n) << "\n";
    }
    else {
        cout << (m - n) << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
