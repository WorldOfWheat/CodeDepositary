#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 5000 + 1

using namespace std;

vector<int> color(MAX);
vector<int> color_b(MAX);
vector<int> graph[MAX];
bitset<MAX> vis;
int cnt;
int cnt2;

bool dfs(int x, int y) {

    vis[x] = 1;
    cnt2++;
    if (!color[x]) {
        color[x] = y ^ 3;
        if (color[x] != color_b[x]) {
            cnt++;
        }
    }
    else if (y ^ 3 != color[x]) {
        return false;
    }
    bool flag = true;
    for (auto i : graph[x]) {

        flag &= color[i] != color[x];
        if (vis[i]) {
            continue;
        }

        flag &= dfs(i, y ^ 3);
    }
    return flag;

}

void solve() {

    int n, m;
    cin >> n >> m;
    rep2 (i, 1, n) {
        int a;
        cin >> a;
        color_b[i] = a + 1;
    }
    rep (i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int ans = 0;
    rep2 (i, 1, n) {
        if (vis[i]) {
            continue;
        }
        cnt = 0;
        cnt2 = 0;
        if (!dfs(i, 1)) {
            cout << "-1" << ln;
            return;
        }
        ans += min(cnt, cnt2 - cnt);
    }
    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
