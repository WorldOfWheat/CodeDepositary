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
#define N 10+1

using namespace std;

vector<int> ve(N);

void solve() {
    int n;
    cin >> n;
    rep (i, 0, n) {
        cin >> ve[i];
    }
    cout << *(max_element(ve.begin(), ve.begin()+n)) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
