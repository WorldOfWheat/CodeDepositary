#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define sp " "
#define ln "\n"

using namespace std;

int n;

void solve() {
    
    cin >> n;
    
    int k = n / 7;
    int ans = (k / 2 * 1) + (k / 2 * 2) + (k % 2);

    int p = n % 7;
    if (k % 2) {
        ans += (p >= 2) + (p >= 4);
    }
    else {
        ans += (p >= 1);
    }

    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
