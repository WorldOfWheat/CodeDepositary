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

vector<pii> ve;
deque<int> de;
deque<int> de2;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i].F;
    }
    rep (i, 0, n) {
        cin >> ve[i].S;
    }
    sort(ve.begin(), ve.end());
    int ans = 0;
    rep (i, 0, n) {
        pii top = ve[i];
        int d = top.F - m;
        while (de.size() && ve[de.front()].F < d) {
            de.pop_front();
        }
        while (de.size() && ve[de.back()].S < top.S) {
            de.pop_back();
        }
        while (de2.size() && ve[de2.front()].F < d) {
            de2.pop_front();
        }
        while (de2.size() && ve[de2.back()].S > top.S) {
            de2.pop_back();
        }
        de.push_back(i);
        de2.push_back(i);
        //cerr << (de.back()) << sp << (de2.back()) << ln;
        ans = max(ans, abs(ve[de.front()].S - ve[de2.front()].S) );
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
