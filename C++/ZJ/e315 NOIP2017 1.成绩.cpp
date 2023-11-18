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

int a, b, c;

void solve() {
    cout << ((a * 0.2) + (b * 0.3) + (c * 0.5)) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> a >> b >> c) solve();

    return 0;
}
