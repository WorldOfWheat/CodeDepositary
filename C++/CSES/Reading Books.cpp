#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n, m;
priority_queue<int, vector<int>, less<int> > pq;

void solve () {

    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    int ans = 2*pq.top();
    int now = 0;

    while (pq.size()) {
        int top = pq.top();
        pq.pop();

        now += top;
        ans = max(ans, now);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
