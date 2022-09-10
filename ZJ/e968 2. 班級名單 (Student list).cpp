#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

set<int> se;

void solve() {

    int n;
    cin >> n;
    rep2 (i, 1, n) {
        se.insert(i);
    }
    rep (i, 0, 3) {
        int a;
        cin >> a;
        se.erase(a);
    }
    int cnt = se.size();
    for (auto it = se.rbegin(); it != se.rend(); it++) {
        cout << "No. " << (*it);
        cnt--;
        if (cnt != 0) {
            cout << (ln);
        }
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
