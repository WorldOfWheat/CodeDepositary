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

void dfs(int x) {
    cout << x << " ";
    if (x == 1) {
        return;
    }
    if (x % 2) {
        dfs(x*3 + 1);
    }
    else {
        dfs(x/2);
    }
}

void solve () {

    cin >> n;
    dfs(n);

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
