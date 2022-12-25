#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18
#define ln '\n'

using namespace std;

int n;
V ans;

void solve() {
    cin >> n;

    int ans2 = 0;
    rep (i, 0, n) {
        int in, in2;
        cin >> in >> in2;

        if (in2 > 100) {
            ans.push_back(in);
            ans2 += (in2 - 100) * 5;
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size()) {
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << ln;
    }
    cout << ans2 << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}

