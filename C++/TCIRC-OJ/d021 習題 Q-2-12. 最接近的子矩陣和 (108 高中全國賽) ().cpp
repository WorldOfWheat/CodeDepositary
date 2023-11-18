#include <bits/stdc++.h>
#define int long long
#define V vector<int>
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

vv ve;
vv pf;

void solve() {
    int k;
    int n, m;
    cin >> k >> n >> m;
    ve.resize(n);
    for (auto &i : ve) {
        i.resize(m);
    }
    pf.resize(n+1);
    for (auto &i : pf) {
        i.resize(m+1);
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }
    rep2 (i, 1, n) {
        rep2 (j, 1, m) {
            pf[i][j] = pf[i-1][j] + ve[i-1][j-1];
        }
    }
    /*rep2 (i, 1, n) {
        rep2 (j, 1, m) {
            cerr << pf[i][j] << sp;
        }
        cerr << ln;
    }*/
    int ans = 0;
    rep (i, 0, n) {
        rep2 (j, i+1, n) {
            multiset<int> ms;
            ms.insert(0);
            int pf2 = 0;
            rep2 (o, 1, m) {
                pf2 += pf[j][o] - pf[i][o];
                int re = pf2 - k;
                auto it = ms.lower_bound(re);
                if (it != ms.end()) {
                    ans = max(ans, pf2 - *it);
                }
                ms.insert(pf2);
            }
        }
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
