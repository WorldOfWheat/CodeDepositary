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

int n, m;
V ve;
deque<int> de;

void solve() {
    ve.clear();
    ve.resize(n);
    de.clear();
    m = min(n, m);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    rep (i, 0, m) {
        while (de.size() && ve[de.back()] >= ve[i]) {
            de.pop_back();
        }
        de.push_back(i);
    }
    cout << (ve[de.front()]);
    rep (i, m, n) {
        while (de.size() && ve[de.back()] >= ve[i]) {
            de.pop_back();
        }
        while (de.size() && de.front() < (i - m + 1) ) {
            de.pop_front();
        }
        de.push_back(i);
        cout << sp << (ve[de.front()]);
    }
    cout << ln;
    de.clear();
    rep (i, 0, m) {
        while (de.size() && ve[de.back()] <= ve[i]) {
            de.pop_back();
        }
        de.push_back(i);
    }
    cout << (ve[de.front()]);
    rep (i, m, n) {
        while (de.size() && ve[de.back()] <= ve[i]) {
            de.pop_back();
        }
        while (de.size() && de.front() < (i - m + 1) ) {
            de.pop_front();
        }
        de.push_back(i);
        cout << sp << (ve[de.front()]);
    }
    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) solve();

    return 0;
}
