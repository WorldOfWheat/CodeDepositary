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
int _type;
map<int, int> ma;

void discrete(V &x) {
    V temp = x;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    _type = temp.size();
    for (auto &i : x) {
        auto it = lower_bound(temp.begin(), temp.end(), i);
        i = distance(temp.begin(), it) + 1;
    }
}

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    discrete(ve);
    int ans = 1e18;
    int cnt = 0;
    int l = 0;
    int r;
    for (r = 0; r < n; r++) {
        int top = ve[r];
        if (!ma[top]) {
            cnt++;
        }
        ma[top]++;
        while (ma[ve[l]] > 1) {
            ma[ve[l]]--;
            l++;
        }
        if (cnt == _type) {
            ans = min(ans, r - l + 1);
        }
    }
    cout << (ans) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
