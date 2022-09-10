#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
vector<int> ve_input;
vector<int> ve2_input;
vector<int> ve;
vector<int> ve2;

int dfs() {

    int ans = (int) -1e18;

    int k = 0;
    while (k < ve.size()) {
        int dp = (int) -1e18;
        int l = k;
        int r = 0;
        while (l < ve.size()) {
            dp = max(dp + ve[l]*ve2[r], ve[l]*ve2[r]);
            ans = max(ans, dp);
            l++;
            r++;
            if (r == ve2.size()) {
                dp = (int) -1e18;
                r = 0;
            }
        }
        k++;
    }
    //cout << ans << "\n";
    return ans;
}

void solve() {

    cin >> n >> m;

    ve_input.resize(n);
    ve2_input.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> ve_input[i];
    }
    for (int i = 0 ; i < m; i++) {
        cin >> ve2_input[i];
    }

    if (ve_input.size() >= ve2_input.size()) {
        ve.assign(ve_input.begin(), ve_input.end());
        ve2.assign(ve2_input.begin(), ve2_input.end());
        ve.resize(n);
        ve2.resize(m);
    }
    else {
        ve2.assign(ve_input.begin(), ve_input.end());
        ve.assign(ve2_input.begin(), ve2_input.end());
        ve2.resize(n);
        ve.resize(m);
    }

    int ans = dfs();
    reverse(ve.begin(), ve.end());
    ans = max(ans, dfs());
    reverse(ve.begin(), ve.end());
    reverse(ve2.begin(), ve2.end());
    ans = max(ans, dfs());
    reverse(ve.begin(), ve.end());
    ans = max(ans, dfs());

    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
