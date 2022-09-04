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
    ve.resize(n+2);
    ve[0] = 1e18;
    rep2 (i, 1, n) {
        cin >> ve[i];
    }
    ve[n+1] = 1e18;
    int m;
    cin >> m;
    bool flag;
    if (ve[m-1] < ve[m+1]) {
        flag = false;
    }
    else {
        flag = true;
    }
    while (true) {
        int top = ve[m];
        if ( (flag && ve[m+1] > ve[m]) || (!flag && ve[m-1] > ve[m]) ) {
            cout << m << ln;
            return;
        }
        if (flag) {
            m++;
        }
        else {
            m--;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
