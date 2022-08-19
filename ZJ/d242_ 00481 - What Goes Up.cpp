#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;
vector<int> ve;
vector<int> ve_dp;
vector<int> ve_mini;

void solve() {

    while (cin >> n) {
        ve.push_back(n);
    }

    int _size = ve.size();
    ve.resize(_size);
    ve_dp.resize(_size+1);
    ve_dp[1] = 1;
    ve_mini.push_back(ve.front());

    int ans = 1;
    for (int i = 2; i <= _size; i++) {
        if (ve[i-1] > ve_mini.back()) {
            ans++;
            ve_dp[i] = ans;
            ve_mini.push_back(ve[i-1]);
        } else {
            auto it = (lower_bound(ve_mini.begin(), ve_mini.end(), ve[i-1]));
            *it = ve[i-1];
            ve_dp[i] = distance(ve_mini.begin(), it) + 1;
        }
    }
    cout << ans << "\n" << "-" << "\n";
    vector<int> ve_ans;
    for (int i = _size; i >= 1; i--) {
        if (ve_dp[i] == ans) {
            ve_ans.push_back(ve[i-1]);
            ans--;
        }
    }
    for (auto it = ve_ans.rbegin(); it != ve_ans.rend(); it++) {
        cout << (*it) << "\n";
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
