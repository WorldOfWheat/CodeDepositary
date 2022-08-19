#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

void solve() {

    int n, m, o;
    cin >> n >> m >> o;
    while (n != m) {
        cout << n << sp;
        n += o;
    }
    cout << m;
    cout << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
