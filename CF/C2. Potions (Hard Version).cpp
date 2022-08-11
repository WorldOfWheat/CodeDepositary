#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n;
vector<int> ve;
priority_queue<int> pq;

void solve () {

    cin >> n;
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int ans = 0;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (ve[i] >= 0) {
            now += ve[i];
            ans++;
        }
        else if (ve[i] + now >= 0) {
            ans++;
            now += ve[i];
            pq.push ( abs(ve[i]) );
        }
        else if (pq.size() && abs(ve[i]) < pq.top()) {
            now += pq.top() + ve[i];
            pq.pop();
            pq.push( abs(ve[i]) );
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
