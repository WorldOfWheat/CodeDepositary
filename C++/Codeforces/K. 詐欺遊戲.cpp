#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 2e5 + 1

using namespace std;

vector<int> ve(MAX);
vector<int> ve2;
vector<bool> ve3(MAX);

void solve() {

    int n;
    cin >> n;
    rep (i, 0, n) {
        cin >> ve[i];
    }

    int m;
    cin >> m;
    rep (i, 0, m) {
        int a;
        cin >> a;
        ve2.pb(a);
        ve2.back()--;
    }
    int cnt = n;
    int add = 0;
    rep (i, 0, m) {
        int top = ve2[i];
        ve[top] -= (i + 1) * cnt;
        add += i + 1;
        if (ve[top] + add < 0) {
            ve[top] += add;
            cnt--;
            ve3[top] = true;
        }
    }
    rep (i, 0, n) {
        if (!ve3[i]) {
            ve[i] += add;
        }
        cout << (ve[i]) << sp;
    }
    cout << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
