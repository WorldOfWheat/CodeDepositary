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

using namespace std;

int dfs() {
    string str;
    cin >> str;
    if (str[0] == 'f') {
        int a = dfs();
        return 2*a - 3;
    }
    if (str[0] == 'g') {
        int a = dfs();
        int b = dfs();
        return 2*a + b - 7;
    }
    if (str[0] == 'h') {
        int a = dfs();
        int b = dfs();
        int c = dfs();
        return 3*a - 2*b + c;
    }
    return atoi(str.c_str());
}

void solve() {
    cout << dfs() << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
