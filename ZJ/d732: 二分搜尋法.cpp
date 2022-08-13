#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m;
vector<int> ve;

int _binary_search(int l, int r, int x) {
    if (l > r) {
        return (ve[r] == x) ? (r+1) : 0;
    }
    int mid = (l + r) >> 1;
    if (ve[mid] <= x) {
        return _binary_search(mid+1, r, x);
    }
    if (ve[mid] > x) {
        return _binary_search(l, mid-1, x);
    }
}

void solve() {

    cin >> n >> m;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << (_binary_search(0, ve.size()-1, a)) << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
