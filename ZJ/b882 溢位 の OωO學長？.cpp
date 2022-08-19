#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

void solve() {

    int n, m, o;
    cin >> n >> m >> o;
    m += o / 60;
    o %= 60;

    n += m / 60;
    m %= 60;

    n %= 24;
    cout << (n < 10 ? "0" : "") << n << ":" <<
            (m < 10 ? "0" : "") << m << ":" <<
            (o < 10 ? "0" : "") << o << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
