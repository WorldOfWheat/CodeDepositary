#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

struct cmp {
    bool operator()(pii x, pii y) {
        return x.S < y.S;
    }
};


int n;
priority_queue<pii, vector<pii>, cmp> pq;

void solve() {

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push( mp(a, b) );
    }
    int ans = 0;
    int now = 0;
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        now += top.F;
        ans = max(ans, now + top.S);
    }
    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) solve();

    return 0;
}
