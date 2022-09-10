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

using namespace std;

string str;
int ans;
int k;

void dfs(int x) {
    char top = str[k];
    if (top == '2') {
        k++;
        dfs(x >> 1);
        k++;
        dfs(x >> 1);
        k++;
        dfs(x >> 1);
        k++;
        dfs(x >> 1);
        return;
    }
    if (top == '1') {
        ans += x*x;
        return;
    }
    if (top == '0') {
        return;
    }
}

void solve() {
    cin >> str;
    int n;
    cin >> n;

    dfs(n);

    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
