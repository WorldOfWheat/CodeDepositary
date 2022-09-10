#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<string>>
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

int n;
vector<int> ve(15+1);
int _index;

void dfs(int x, int y) {
    if (x == n) {
        cout << "{";
        rep (i, 0, _index) {
            if (i != 0) {
                cout << ",";
            }
            cout << ve[i];
        }
        cout << "}" << ln;
        return;
    }
    if (y) {
        ve[_index] = x + 1;
        _index++;
        dfs(x+1, y-1);
        _index--;
    }
    if (n - x > y) {
        dfs(x + 1, y);
    }
}

void solve() {
    cin >> n;
    cout << "{0}" << ln;
    rep2 (i, 1, n) {
        dfs(0, i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
