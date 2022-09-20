#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

struct cmp{
    bool operator()(pii x, pii y) {
        return x.S > y.S;
    }
};

int n, m;
priority_queue<pii, vector<pii>, cmp> pq;
multiset<int> ms;

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    for (int i = 0; i < m; i++) {
        ms.insert(0);
    }
    int ans = 0;
    while (pq.size()) {
        pii top = pq.top();
        pq.pop();
        auto it = ms.upper_bound(top.F);
        if (it == ms.begin()) continue;
        it--;
        ms.erase(it);
        ms.insert(top.S);
        ans++;
    }

    cout << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
