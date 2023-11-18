#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

vector<int> graph[(int) 1e4 + 1];
int ans;

bool dfs(int x, int y) {
    bool flag = false;
    for (auto i : graph[x]) {
        if (i != y && !dfs(i, x)) {
            flag = true;
        }
    }
    ans += flag;
    return flag;
}

void solve() {

    int n;
    cin >> n;
    rep (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, 1);
    cout << (ans) << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
