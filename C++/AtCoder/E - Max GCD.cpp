#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep2(x, y, z) for (int x = y; x >= 0; x--)
#define ln "\n"
#define sp " "

using namespace std;

int n, m;
vector<int> ve;

bool check(int x) {

    vector<int> ve2;
    rep (i, 0, n) {
        int a = ve[i] % x;
        if (a) {
            ve2.push_back(a);
        }
    }
    sort(ve2.begin(), ve2.end());
    int ans = 0;
    int l = 0, r = ve2.size() - 1;
    while (l < r) {
        int a = min(ve2[l], x - ve2[r]);
        ans += a;
        ve2[l] -= a;
        ve2[r] += a;
        if (ve2[l] == 0) {
            l++;
        }
        if (ve2[r] == x) {
            r--;
        }
    }
    return (ans <= m);

}

void solve() {

    cin >> n >> m;
    ve.resize(n);
    int sum = 0;
    rep (i, 0, n) {
        cin >> ve[i];
        sum += ve[i];
    }
    int ans = -1e18;
    rep2 (i, 1, (int) sqrt(sum)) {
        //cerr << i << ln;
        if (sum % i == 0) {
            if (check(i)) {
                ans = max(ans, i);
            }
            if (check(sum / i)) {
                ans = max(ans, sum / i);
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
