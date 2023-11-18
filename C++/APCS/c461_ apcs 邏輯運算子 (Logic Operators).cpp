#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

void solve() {

    int a, b, c;
    cin >> a >> b >> c;
    bool flag = false;
    if ((a && b) == c) {
        cout << "AND" << "\n";
        flag = true;
    }
    if ((a || b) == c) {
        cout << "OR" << "\n";
        flag = true;
    }
    if (((a && !b) || (!a && b)) == c) {
        cout << "XOR" << "\n";
        flag = true;
    }
    if (!flag) {
        cout << "IMPOSSIBLE" << "\n";
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
