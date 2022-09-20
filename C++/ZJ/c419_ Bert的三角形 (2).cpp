#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j >= 1; j--) {
            cout << "_";
        }
        for (int j = i; j >= 1; j--) {
            cout << "*";
        }
        cout << "\n";
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
