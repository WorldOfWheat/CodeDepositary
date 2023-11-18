#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m;
vector<int> table;
vector<pii> ve;
multiset<int> ms;

void solve() {

    cin >> n >> m;

    table.resize(m);
    ve.resize(m);
    fill(table.begin(), table.end(), -1);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        ve[i].F = a;
        ve[i].S = i;
    }

    for (int i = 0; i < m && ms.size(); i++) {

        pii top = ve[i];
        auto it = ms.upper_bound(top.F);
        if (it != ms.begin()) it--;
        if ( (*it) <= top.F ) {
            table[top.S] = *it;
            ms.erase(it);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << table[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
