#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

void solve() {

    int n;
    cin >> n;
    int k = 2;
    stringstream ss;
    while (n > 1) {
        int cnt = 0;
        while (n % k == 0) {
            cnt++;
            n /= k;
        }
        if (cnt != 0) {
            if (ss.str().length() != 0) {
                ss << " * ";
            }
            if (cnt != 1) {
                ss << k << "^" << cnt;
            }
            else {
                ss << k;
            }
        }
        k++;
    }
    cout << (ss.str()) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
