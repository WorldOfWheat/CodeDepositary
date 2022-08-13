#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;
priority_queue<pii, vector<pii>, greater<pii>> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

void solve() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    int ans = 0;

    while (pq.size()) {
        pii top = pq.top();
        pq.pop();

        if (pq2.empty() || pq2.top() <= top.F) {
            if (pq2.size()) {
                pq2.pop();
            }
            pq2.push(top.S);

        }
        else {
            pq2.push(top.S);
        }
        int temp = pq2.size();
        ans = max(ans, temp);
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
