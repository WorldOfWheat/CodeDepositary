#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n;
int cnt;
stringstream ss;

void dfs(int x, int y, int z, int w) {
    if (w == 1) {
        ss << x << " " << z << "\n";
        cnt++;
        return;
    }
    dfs(x, z, y, w - 1);
    ss << x << " " << z << "\n";
    cnt++;
    dfs(y, x, z, w - 1);
}

void solve () {

    cin >> n;
    dfs(1, 2, 3, n);
    cout << cnt << "\n" << (ss.str()) << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
