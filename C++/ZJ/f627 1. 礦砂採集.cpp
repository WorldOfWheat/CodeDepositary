#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

struct cmp{
    bool operator()(pii x, pii y){
        return x.S < y.S;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

void solve() {
    int n, m;
    cin >> n >> m;
    rep (i, 0, n) {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    int ans = 0;
    while (pq.size() && m) {
        pii top = pq.top();
        pq.pop();
        int k = min(top.F, m);
        ans += top.S * k;
        m -= k;
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
