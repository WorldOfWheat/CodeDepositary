#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;
priority_queue<int, vector<int>, less<int>> pq2;

void solve() {
    int n;
    cin >> n;
    rep (i, 0, n) {
        int a;
        cin >> a;
        pq.push(a);
    }
    rep (i, 0, n) {
        int a;
        cin >> a;
        pq2.push(a);
    }
    int ans = 0;
    while (pq.size() && pq2.size()) {
        if (pq.top() < pq2.top()) {
            ans++;
            pq2.pop();
        }
        pq.pop();
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
