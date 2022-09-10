#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> dp((int) 1e6, (int) 1e18);

void solve() {

    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++) {
        string str = to_string(i);
        for (int j = 0; j < str.length(); j++) {
            int top = str[j] - '0';
            if (top == 0) {
                continue;
            }
            dp[i] = min(dp[i - top] + 1, dp[i]);
        }
        /*for (int j = 1; j <= i; j++) {
            cerr << dp[j] << sp;
        }
        cerr << ln;*/
    }
    cout << (dp[n]) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
