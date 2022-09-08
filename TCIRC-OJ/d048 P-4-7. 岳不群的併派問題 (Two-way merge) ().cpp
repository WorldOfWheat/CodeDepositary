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

priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
    int n;
    cin >> n;
    rep (i, 0, n) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a + b);
        pq.push(a +b);
    }
    cout << (pq.top()) << ln << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
