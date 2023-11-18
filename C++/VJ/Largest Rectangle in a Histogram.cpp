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

int n;
V ve;
V vel;
V ver;
deque<int> de;

void solve() {
    de.clear();
    vel.clear();
    ver.clear();
    ve.resize(n+2);
    vel.resize(n+2);
    ver.resize(n+2);
    ve[0] = -1;
    ve[n+1] = -1;
    rep2 (i, 1, n) {
        cin >> ve[i];
    }
    rep2 (i, 1, n+1) {
        while (de.size() && ve[de.back()] > ve[i]) {
            vel[de.back()] = i;
            de.pop_back();
        }
        de.push_back(i);
    }
    de.clear();
    rrep (i, n, 0) {
        while (de.size() && ve[de.back()] > ve[i]) {
            ver[de.back()] = i;
            de.pop_back();
        }
        de.push_back(i);
    }
    int ans = 0;
    rep2 (i, 1, n) {
        ans = max(ans, ve[i] * (vel[i] - ver[i] - 1));
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n && n) solve();

    return 0;
}
