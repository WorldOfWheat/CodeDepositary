#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second
#define MAX 30000

using namespace std;

int n;
vector<int> ve_dp(MAX + 1);

void solve() {

    ve_dp[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        ve_dp[i] += ve_dp[i-1];
    }
    for (int i = 5; i <= MAX; i++) {
        ve_dp[i] += ve_dp[i-5];
    }
    for (int i = 10; i <= MAX; i++) {
        ve_dp[i] += ve_dp[i-10];
    }
    for (int i = 25; i <= MAX; i++) {
        ve_dp[i] += ve_dp[i-25];
    }
    for (int i = 50; i <= MAX; i++) {
        ve_dp[i] += ve_dp[i-50];
    }
    while (cin >> n) {
        if (ve_dp[n] == 1) {
            cout << "There is only 1 way to produce " << n << " cents change." << "\n";
        } else {
            cout << "There are " << ve_dp[n] << " ways to produce " << n << " cents change." << "\n";
        }
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
