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

V ve;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cont = 0;
    int cnt = 0;
    int ans = 0;
    int last = 3;
    if (n == 1) {
        rep (i, 0, str.length()) {
            bool top = isupper(str[i]);
            if (top != last) {
                cont++;
                ans = max(ans, cont);
            }
            else {
                cont = 1;
            }
            last = top;
        }
        cout << ans << ln;
        return;
    }
    rep (i, 0, str.length()) {
        bool top = isupper(str[i]);
        if (last == top) {
            cont++;
            if (cont == n) {
                cnt += n;
                ans = max(ans, cnt);
            }
            if (cont > n) {
                cnt = n;
            }
        }
        else {
            if (cont < n) {
                cnt = 0;
            }
            cont = 1;
        }
        last = top;
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
