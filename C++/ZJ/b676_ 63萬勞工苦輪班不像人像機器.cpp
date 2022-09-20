#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;

void solve() {

    switch(n%5) {
        case 0:
            cout << "U" << ln;
            break;

        case 1:
            cout << "G" << ln;
            break;

        case 2:
            cout << "Y" << ln;
            break;

        case 3:
            cout << "T" << ln;
            break;

        case 4:
            cout << "I" << ln;
            break;

    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
