#include <bits/stdc++.h>
#define int long long
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
#define N 26+1
#define M 10009

using namespace std;

vector<int> ve(N+1);
int n;
int ans = 0;

void dfs(int x, int sum) {
    //cerr << x << sp << sum << ln;
    if (x == n) {
        if (sum == 1) {
            ans++;
        }
        return;
    }
    dfs(x+1, (sum*ve[x] % M) );
    dfs(x+1, sum);
}

void solve() {
    cin >> n;
    rep (i, 0, n) {
        cin >> ve[i];
    }
    dfs(0, 1);
    cout << (ans-1) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
