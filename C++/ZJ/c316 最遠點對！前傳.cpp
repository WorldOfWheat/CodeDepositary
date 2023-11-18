#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln '\n'
#define sp " "

using namespace std;

vector<pii> ve;

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].F >> ve[i].S;
    }
    int maxi = -1e18, maxi2, maxi3;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x1 = ve[i].F;
            int y1 = ve[i].S;
            int x2 = ve[j].F;
            int y2 = ve[j].S;
            int a = (x1 - x2);
            int b = (y1 - y2);
            int dis = sqrt(a*a + b*b);
            if (dis > maxi) {
                maxi = dis;
                maxi2 = i;
                maxi3 = j;
            }
        }
    }
    cout << (maxi2) << sp << maxi3 << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
