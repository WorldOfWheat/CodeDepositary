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

void solve() {

    cin >> n;
    int k = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (i == 1) {
            k = a;
            ans = a;
            continue;
        }
        k = max((int) a, k+a);
        ans = max(ans, k);
    }
    cout << ans << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
