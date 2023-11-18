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

vector<int> ve;

void _discrete(vector<int> &x) {
    vector<int> temp = x;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (auto &i : x) {
        i = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
    }
}

void solve() {
    int n;
    cin >> n;
    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }
    _discrete(ve);
    for (auto i : ve) {
        cout << i << sp;
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
