#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
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

string str, str2;
vv dp(1, vector<int>(1));

void solve() {

    int len = str.length();
    int len2 = str2.length();

    dp.resize(len+1);
    for (auto& i : dp) {
        i.resize(len2+1);
    }

    rep2 (i, 1, len) {
        rep2 (j, 1, len2) {
            if (str[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                continue;
            }
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << (dp[len][len2]) << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str >> str2) solve();

    return 0;

}
