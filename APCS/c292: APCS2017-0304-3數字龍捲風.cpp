#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ln "\n"
#define sp " "
#define rep(x, y) for (int x = 0; x < y; x++)

using namespace std;

int arr[49+1][49+1];

void solve() {

    int n, m;
    cin >> n >> m;
    rep (i, n) {
        rep (j, n) {
            cin >> arr[j][i];
        }
    }

    int x, y;
    x = y = n >> 1;
    int k = 0, k2 = 1;
    int dir = m;
    stringstream ss;
    while (true) {
        k++;
        rep(i, k2) {
            ss << arr[x][y];
            switch (dir) {
                case 0:
                    x--;
                    break;

                case 1:
                    y--;
                    break;

                case 2:
                    x++;
                    break;

                case 3:
                    y++;
                    break;
            }
        }
        if (x >= n || y >= n || x < 0 || y < 0) {
            break;
        }
        if (k == 2) {
            k2++;
            k = 0;

        }
        dir++;
        dir %= 3+1;
    }
    cout << (ss.str()) << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
