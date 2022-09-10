#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << endl
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, g, g2, t;
    cin >> n >> g >> g2 >> t;
    vector<int> v(n+1);
    vector<int> v2(n+1);
    v[0] = 0;
    v2[0] = 0;
    int sum = 0;
    int sc = 0;
    int sc2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sc += v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v2[i];
        sc2 += v2[i];
        sum += v2[i];
    }
    if (sc + sc2 < t) {
        cout << -1 << endl;
        return 0;
    }
    sort(v.begin(), v.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
/*
    db("");
    for (int i = 0; i <= n-1; i++) {
        cout << v[i] << " ";
    }
    db("");
    for (int i = 0; i <= n-1; i++) {
        cout << v2[i] << " ";
    }
    db("");
*/
    int mini = 1e18;
    int r = n;
    int sum_u = 0;
    for (int i = 0; i <= n; i++) {
        //db(r);
        while (sum_u + sum >= t && r >= 0) {
            mini = min(mini, i*g + r*g2);
            if (r-1 >= 0) sum -= v2[r-1];
            r--;
        }
        if (i < n) sum_u += v[i];
    }
    cout << mini << endl;

    return 0;
}
