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

int n, m;
vector<int> ve;
map<int, int> ma;
map<int, int> ma2;
bool sw = true;

void dfs(int x, int y, int value, bool oper) {
    if (x == y) {
        if (oper) {
            ma[value]++;
        }
        else {
            ma2[value]++;
        }
        return;
    }
    dfs(x+1, y, value, oper);
    dfs(x+1, y, value * ve[x] % m, oper);
}

int qpow(int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
}

void solve() {
    cin >> n >> m;

    ve.resize(n);

    rep (i, 0, n) {
        cin >> ve[i];
    }

    int mid = n >> 1;

    dfs(0, mid, 1, true);
    ma[1]--;
    dfs(mid, n, 1, false);
    ma2[1]--;

    int ans = (ma[1] + ma2[1]) % m;

    for (auto i : ma) {
        int f = i.F;
        int s = i.S;
        int re = qpow(f, m-2, m);
        auto it = ma2.find(re);
        if (it == ma2.end()) {
            continue;
        }
        ans += s * (it->S);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
