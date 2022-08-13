#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m, o;
priority_queue<int, vector<int>, less<int> > pq;
multiset<int> ms;

void solve() {

    cin >> n >> m >> o;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    //cerr << "\n";
    int ans = 0;
    while (pq.size()) {
        int top = pq.top();
        pq.pop();
        if (ms.empty()) {
            break;
        }
        int remain_a = top - o;
        int remain_b = top + o;
        //cerr << remain_a << " " << remain_b << "\n";
        auto it = ms.lower_bound(remain_a);
        auto it2 = ms.upper_bound(remain_b);
        it2--;
        //cerr << (*it) << " " << (*it2) << "\n";
        if (remain_a <= (*it2) && (*it2) <= remain_b) {
            ms.erase(it2);
            ans++;
        }
        else if (remain_a <= (*it) && (*it) <= remain_b) {
            ms.erase(it);
            ans++;
        }
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
