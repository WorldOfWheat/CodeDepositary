#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    set<int> s;
    s.insert(0);
    s.insert(m);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (n--) {
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(b, a));
    }
    int cost = 0;
    while (!pq.empty()) {
        int p = pq.top().second;
        pq.pop();
        s.insert(p);
        auto it = s.upper_bound(p);
        auto it2 = s.lower_bound(p);
        it2--;
        cost += abs(*it - *it2);
    }
    cout << cost << endl;

    return 0;
}
