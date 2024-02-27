#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define ln "\n"
#define sp " "

using namespace std;

vector<int> ve;

void solve() {

    int in;
    while (cin >> in, in) {
        ve.push_back(in);
    }
    sort(ve.begin(), ve.end(), [](int x, int y) {

        if (x % 7 == 0 && y % 7 != 0) {
            return true;
        } else if (x % 7 != 0 && y % 7 == 0) {
            return false;
        }

        if (x % 7 == 0 && y % 7 == 0) {
            return (x % 70 > y % 70);
        }

        return (x % 77 < y % 77);

    });
    cout << (ve.front()) << ln;
    /*for (auto i : ve) {
        cerr << i << sp;
    }
    cerr << ln;*/

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
