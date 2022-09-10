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
    switch (n) {
        case 1:
            if (m >= 8) {
                cout << "PASS!" << "\n";
            }
            else {
                cout << "FAIL! You see see you!" << "\n";
            }
            break;
        case 2:
            if (m >= 9) {
                cout << "PASS!" << "\n";
            }
            else {
                cout << "FAIL! You see see you!" << "\n";
            }
            break;
        case 3:
            if (m >= 10) {
                cout << "PASS!" << "\n";
            }
            else {
                cout << "FAIL! You see see you!" << "\n";
            }
            break;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
