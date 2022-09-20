
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln '\n'
#define mod (int)1e9+7

using namespace std;

int n;
vector<int> table((int) 1e6+1);

int dfs(int x) {
    if (x < 0) {
        return 0;
    }
    int a = table[x];
    if (a != 0) {
      return a;
    }
    int b = 0;
    for (int i = 1; i <= 6; i++) {
        b += dfs(x - i);
        b %= mod;
    }
    table[x] = b;
    return b;
}

void solve() {

    table[0] = 1;
    cin >> n;
    cout << dfs(n) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
