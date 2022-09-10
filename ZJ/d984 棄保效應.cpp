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

vector<pii> ve(3);

void solve() {
    rep (i, 0, 3) {
        ve[i].S = i;
    }
    sort(ve.begin(), ve.end());
    ve[1].F += ve[0].F;
    sort(ve.begin(), ve.end());
    cout << ( (char) ((ve[2].S) + 'A') ) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> (ve[0].F) >> (ve[1].F) >> (ve[2].F)) solve();

    return 0;
}
