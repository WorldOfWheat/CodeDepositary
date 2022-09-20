
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
 
using namespace std;
__attribute__((optimize("-O3")))
 
set<pii> se;
bool column[8+1];
bool row[8+1];
int ans;
int m[8+1][8+1];
void dfs(int x) {
    if (x == 8) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (column[i] || m[x][i] == '*') continue;
        for (auto a : se) {
            if (abs(a.first - i) == abs(a.second - x)) {
                goto stop;
            }
        }
        se.insert({i, x});
        column[i] = true;
        dfs(x+1);
        se.erase({i, x});
        column[i] = false;
        stop:
            continue;
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    for (int i = 0; i < 8; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++) {
            m[i][j] = str[j];
        }
    }
    dfs(0);
    cout << ans << "\n";
 
    return 0;
}
