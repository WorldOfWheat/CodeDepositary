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
vector<int> v(200000+5, 0);
vector<int> v2(5000+5, 0);

bool check(int x) {
    int k = 1;
    int cont = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] < x) {
            cont = 0;
            continue;
        }
        cont++;
        //cerr << cont << endl;
        if (v2[k] <= cont) {
            k++;
            cnt++;
            cont = 0;
        }
    }
    return (cnt >= m);
}

void solve() {
    cin >> n >> m;
    int maximum = -1e18;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        maximum = max(maximum, v[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> v2[i];
    }
    int l = 1, r = maximum;
    //cerr << check(5) << endl;
    while (l <= r) {
        int mid = (l + r) / 2;
        //cerr << mid << "\n";
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
