#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

vector<int> ve;

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    ve.erase( unique(ve.begin(), ve.end()), ve.end());
    cout << ve.size() << ln;
    for (auto i : ve) {
        cout << i << sp;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
