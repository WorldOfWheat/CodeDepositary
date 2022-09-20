#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<pii>>
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

void solve() {

    string str;
    string str2;
    cin >> str >> str2;
    int len = str.length();
    int len2 = str2.length();

    vv dp(len+1, vector<pii>(len2+1));

    rep2 (i, 1, len) {
        rep2 (j, 1, len2) {
            if (str[i-1] == str2[j-1]) {
                dp[i][j].F = dp[i-1][j-1].F + 1;
                dp[i][j].S = 1;
                continue;
            }
            if (dp[i-1][j].F > dp[i][j-1].F) {
                dp[i][j].F = dp[i-1][j].F;
                dp[i][j].S = 2;
            }
            else {
                dp[i][j].F = dp[i][j-1].F;
                dp[i][j].S = 3;
            }
        }
    }
    stringstream ss;
    int now_x = len;
    int now_y = len2;
    while (now_x != 0 && now_y != 0) {
        switch (dp[now_x][now_y].S) {
            case 1:
                now_x--;
                now_y--;
                ss << str[now_x];
                break;

            case 2:
                now_x--;
                break;

            case 3:
                now_y--;
                break;

        }
    }
    string ans = ss.str();
    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << (*it);
    }
    cout << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
