#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m, k;
vector<int> ve;

void solve() {

    cin >> n;
    ve.push_back(-1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ve.push_back(a);
    }
    sort(ve.begin(), ve.end());

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a;
        //cout << endl;
        cin >> a;
        auto it = lower_bound(ve.begin(), ve.end(), a );
        auto it2 = upper_bound(ve.begin(), ve.end(), a );

        cout << distance(it, it2) << "\n";

    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
