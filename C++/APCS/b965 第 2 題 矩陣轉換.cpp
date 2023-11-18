#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define vv vector<vector<int>>

using namespace std;

int n, m, k;
vv ve(10, vector<int>(10));
stack<int> st;

vv ro(vv x) {
    vv res(x[0].size(), vector<int>(x.size()));
    int a = 0, b = 0;
    rep (i, 0, n) {
        rrep (j, m-1, 0) {
            res[a][b] = x[i][j];
            a++;
        }
        a = 0;
        b++;
    }
    swap(n, m);
    return res;
}

vv fl(vv x) {
    vv res(x.size(), vector<int>(x[0].size()));
    int a = 0, b = 0;
    rrep (i, n-1, 0) {
        rep (j, 0, m) {
            res[a][b] = x[i][j];
            b++;
        }
        b = 0;
        a++;
    }
    return res;
}

void solve() {

    ve.resize(n);
    rep (i, 0, n) {
        ve[i].resize(m);
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }
    rep (i, 0, k) {
        int a;
        cin >> a;
        st.push(a);
    }
    while (st.size()) {
        if (st.top()) {
            ve = fl(ve);
        }
        else {
            ve = ro(ve);
        }
        st.pop();
    }
    cout << n << sp << m << ln;
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (j != 0) {
                cout << sp;
            }
            cout << (ve[i][j]);
        }
        cout << ln;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m >> k) solve();

    return 0;

}
