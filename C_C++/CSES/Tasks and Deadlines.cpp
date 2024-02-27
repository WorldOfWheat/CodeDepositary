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
priority_queue<pii, vector<pii>, greater<pii> > pq;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push(mp(a, b));
    }
    int ans = 0;
    int now = 0;
    while (!pq.empty()) {
        pii top = pq.top();
        //cout << top.F << " " << top.S << endl;
        pq.pop();
        now += top.F;
        ans += top.S - now;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
