#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

int n;

void solve() {
    int ans = 0;
    int cnt = 0;
    rep (i, 0, n) {
        int a;
        cin >> a;
        if (a >= 2000) {
            a -= 200;
        }
        ans += a;
    }
    ans -= (ans / 1000) * 100;
    cout << ans << ln;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
