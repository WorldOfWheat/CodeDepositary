#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
vector<int> ve;
int maxi;

bool check(int x) {
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ve[i] > x) {
            return false;
        }
        //cout << (ve[i] + sum) << " " << x << endl;
        if (ve[i] + sum > x) {
            sum = ve[i];
            cnt++;
        } else {
            sum += ve[i];
        }
    }
    if (sum > 0) {
        cnt++;
    }
    return (cnt <= m);
}

void solve() {

    cin >> n >> m;
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int l = 0, r = 1e18;
    while (l <= r) {
        int mid = (l + r) / 2;
        //cout << mid << endl;
        if (check(mid)) {
            r = mid - 1;
        } else {
            //cout << maxi << endl;
            l = mid + 1;
        }
    }
    cout << (r+1) << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
