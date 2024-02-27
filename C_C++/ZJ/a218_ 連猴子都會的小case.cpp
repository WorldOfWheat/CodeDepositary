#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
#define rep(x, y) for (int x = 0; x <= y; x++)
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n;
set<int> se;
vector<pii> ve(9+1);

bool cmp(pii x, pii y) {
    return (x.F > y.F || (x.F == y.F && x.S < y.S));
}

void solve() {

    se.clear();
    rep(i, 9) {
        ve[i].F = 0;
        ve[i].S = i;
    }
    rep(i, n-1) {
        int a;
        cin >> a;
        ve[a].F++;
        se.insert(a);
    }
    sort(ve.begin(), ve.end(), cmp);
    rep(i, se.size()-1) {
        cout << ve[i].S << sp;
    }
    cout << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
