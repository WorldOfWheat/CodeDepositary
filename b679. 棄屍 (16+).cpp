#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;

bool check(int x) {
    int sum = (1+x)*x / 2;
    return (sum >= n);
}

void solve() {

    int l = 0, r = (2ll << 30) - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << (r+1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
