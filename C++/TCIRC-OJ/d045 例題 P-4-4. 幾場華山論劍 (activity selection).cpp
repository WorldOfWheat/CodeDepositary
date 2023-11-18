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

struct cmp {
    bool operator()(pii x, pii y) {
        return x.S > y.S;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

void solve() {
    int n;
    cin >> n;
    rep (i, 0, n) {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    int now = -1;
    int ans = 0;
    while (pq.size()) {
        pii top = pq.top();
        if (top.F > now) {
            now = top.S;
            ans++;
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
