#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define N (int) 1e6 + 1

using namespace std;

int n, m;
vector<int> ve(N);
vector<int> pf(N); 
vector<int> sf(N);

int dfs(int l, int r, int level) {
    if (r - l + 1 < 3) {
        return 0;
    }
    if (level == m) {
        return 0;
    }

    int ratio = 0;
    pf.clear();
    pf[l] = 0;
    rep2 (i, l+1, r) {
        ratio += ve[i-1];
        pf[i] = pf[i-1] + ratio;
    }

    ratio = 0;
    sf.clear();
    sf[r] = 0;
    rrep (i, r - 1, l) {
        ratio += ve[i+1];
        sf[i] = sf[i+1] + ratio;
    }
    int mini = 1e18;
    int pos;
    rep2 (i, l+1, r-1) {
        int remain = abs(pf[i] - sf[i]);
        if (mini > remain) {
            pos = i;
            mini = remain;
        }
    }
    int res = ve[pos];
    return res + dfs(l, pos-1, level+1) + dfs(pos+1, r, level+1);

}

void solve() {
    cin >> n >> m;
    rep (i, 0, n) {
        cin >> ve[i];
    }
    cout << (dfs(0, n-1, 0)) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
