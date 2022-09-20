#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

struct disc {
    int up = 1;
    int right = 2;
    int _forward = 4;
};

int n, m;
vector<disc> ve;

void solve() {

    cin >> n >> m;
    ve.resize(n+1);
    for (int i = 0 ; i < m; i++) {
        int oper, oper2;
        cin >> oper >> oper2;
        disc &top = ve[oper];
        int _forward_backup = top._forward;
        int up_backup = top.up;
        int right_backup = top.right;
        if (oper2 == -1) {
            top.up = 7 - _forward_backup;
            top._forward = up_backup;
        }
        else if (oper2 == -2) {
            top.up = 7 - right_backup;
            top.right = up_backup;
        }
        else {
            swap(ve[oper], ve[oper2]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ve[i].up << sp;
    }
    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
