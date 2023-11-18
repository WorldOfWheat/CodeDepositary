#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

ll n, m, o;
vector<ll> ve;
vector<ll> pf;
multiset<ll> ms;

void solve() {

    cin >> n >> m >> o;
    ve.resize(n);
    pf.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> ve[i];
    }

    for (int i = 1; i <= n; ++i) {
        pf[i] = pf[i-1] + ve[i-1];
    }

    ll ans = -1e18;
    for (int i = m; i <= n; ++i) {
        if (i > o) {
            ms.erase(ms.find(pf[i-o-1]));
        }
        ms.insert( pf[i-m] );
        ans = max(ans, pf[i] - *(ms.begin()));
    }
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
