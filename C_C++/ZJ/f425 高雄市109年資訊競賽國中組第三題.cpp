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

double _distance(pii x, pii y) {
    double a = x.F - y.F;
    double b = x.S - y.S;
    return sqrt(a*a + b*b);
}

void solve() {
    double a, b, c;
    cin >> (ve[0].F) >> (ve[0].S);
    cin >> (ve[1].F) >> (ve[1].S);
    cin >> (ve[2].F) >> (ve[2].S);
    a = _distance(ve[0], ve[1]);
    b = _distance(ve[0], ve[2]);
    c = _distance(ve[1], ve[2]);
    double s = (a + b + c) / 2;
    cout << (  (2 * sqrt(s*(s-a)*(s-b)*(s-c) ) ) ) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
