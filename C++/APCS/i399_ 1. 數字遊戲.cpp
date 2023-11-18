#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

set<int> se;
vector<int> ve_table(9+1);

void solve() {

    int a, b, c;
    cin >> a >> b >> c;
    se.insert(a);
    se.insert(b);
    se.insert(c);
    ve_table[a]++;
    ve_table[b]++;
    ve_table[c]++;
    cout << (max({ve_table[a], ve_table[b], ve_table[c]})) << " ";
    for (auto it = se.rbegin(); it != se.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
