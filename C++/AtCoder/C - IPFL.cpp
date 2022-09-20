#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

string str;

void solve() {

    int n;
    cin >> n;

    cin >> str;

    int m;
    cin >> m;

    bool status = false;
    rep (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            c--;
            if (status) {
                if (b < n) {
                    b += n;
                }
                else {
                    b -= n;
                }
                if (c < n) {
                    c += n;
                }
                else {
                    c -= n;
                }
            }
            swap(str[b], str[c]);
            continue;
        }
        status = !status;
    }
    //cout << (status) << ln;
    if (status) {
        cout << (str.substr(n)) << str.substr(0, n) << ln;
        return;
    }
    cout << (str) << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
