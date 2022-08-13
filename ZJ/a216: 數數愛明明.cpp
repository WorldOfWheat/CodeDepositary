#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

ll n;

ll f(ll x) {
    if (x == 1) {
        return 1;
    }
    return (x + f(x - 1));
}

ll g(ll x) {
    if (x == 1) {
        return 1;
    }
    return (f(x) + g(x-1));
}

void solve() {

    cout << (f(n)) << " " << (g(n)) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
