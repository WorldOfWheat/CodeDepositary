#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;
deque<int> de;
map<int, int> ma;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    int cnt = 0;
    rep (i, 0, m) {
        de.push_back(i);
        if (!ma[ve[i]]) {
            cnt++;
        }
        ma[ve[i]]++;
    }
    int ans = cnt;
    rep (i, m, n) {
        if (!ma[ve[i]]) {
            cnt++;
        }
        ma[ve[i]]++;
        de.push_back(i);
        ma[ ve[de.front()] ]--;
        if (!ma[ ve[de.front()] ]) {
            cnt--;
        }
        de.pop_front();
        ans = max(ans, cnt);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
