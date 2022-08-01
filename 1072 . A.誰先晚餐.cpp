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
priority_queue<pii> pq;

void solve() {

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push(mp(b, a));
    }
    int ans = 0;
    int last = 0;
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        last += top.S;
        ans = max(ans, last+top.F);
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        if (n == 0) return 0;
        solve();
    }

    return 0;
}
