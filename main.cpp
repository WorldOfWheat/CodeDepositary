#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

int n;
vector<int> ve;

void solve() {

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = (abs(a*ans)) / (__gcd(ans, a));
    }
    cout << ans << ln;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) solve();

    return 0;
}
