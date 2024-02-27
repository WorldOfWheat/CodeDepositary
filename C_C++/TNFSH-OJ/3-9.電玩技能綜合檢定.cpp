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
    if (n == 100) {
        cout << "S" << "\n";
        return;
    }
    if (90 <= n && n <= 99) {
        cout << "A" << "\n";
        return;
    }
    if (80 <= n && n <= 89) {
        cout << "B" << "\n";
        return;
    }
    if (70 <= n && n <= 79) {
        cout << "C" << "\n";
        return;
    }
    if (60 <= n && n <= 69) {
        cout << "D" << "\n";
        return;
    }
    cout << "F" << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
