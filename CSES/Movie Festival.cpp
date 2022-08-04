
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second
 
using namespace std;
__attribute__((optimize("-O3")))
 
int n;
vector<pii> ve;
 
bool cmp(pii x, pii y) {
    return (x.S < y.S);
}
 
void solve() {
 
    cin >> n;
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        ve[i] = mp(a, b);
    }
    sort(ve.begin(), ve.end(), cmp);
    int last = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ve[i].F >= last) {
            ans++;
            last = ve[i].S;
        }
    }
    cout << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}
