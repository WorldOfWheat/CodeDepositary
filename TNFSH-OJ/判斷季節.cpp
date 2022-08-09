#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

void solve() {

    int a;
    cin >> a;
    if (3 <= a && a <= 5) {
        cout << "Spring!" << "\n";
    }
    if (6 <= a && a <= 8) {
        cout << "Summer!" << "\n";
    }
    if (9 <= a && a <= 11) {
        cout << "Autumn!" << "\n";
    }
    if (12 == a || a <= 2) {
        cout << "Winter!" << "\n";
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
