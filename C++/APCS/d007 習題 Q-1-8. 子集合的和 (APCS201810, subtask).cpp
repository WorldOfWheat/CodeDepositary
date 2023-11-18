#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<string>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define N 26+1

using namespace std;

vector<int> ve(N);
vector<int> _left;
vector<int> _right;

void solve() {
    int n, m;
    cin >> n >> m;
    rep (i, 0, n) {
        cin >> ve[i];
    }
    int mid = n >> 1;
    rep (i, 0, (1 << mid)) {
        int sum = 0;
        rep (j, 0, mid) {
            if ((i >> j) & 1) {
                sum += ve[j];
            }
        }
        _left.pb(sum);
    }
    int mid2 = mid + (n%2);
    rep (i, 0, (1 << mid2)) {
        int sum = 0;
        rep (j, 0, mid2) {
            if ((i >> j) & 1) {
                sum += ve[j+mid];
            }
        }
        _right.pb(sum);
    }
    sort(_right.begin(), _right.end());
    int ans = 0;
    for (auto i : _left) {
        if (i > m) {
            continue;
        }
        int remain = m - i;
        auto it = lower_bound(_right.begin(), _right.end(), remain);
        if (it == _right.begin()) {
            continue;
        }
        it--;
        if (*it + i > m) {
            continue;
        }
        ans = max(ans, *it + i);

    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
