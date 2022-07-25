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
vector<int> v;
pii minimum = mp(1e18, 0);

bool check(int x) {
    vector<int> v2(v.begin(), v.end());
    for (int i = n; i >= 3; i--) {
        if (v2[i] < x) return false;
        int a = min(v[i], v2[i]-x) / 3;
        v2[i-1] += a;
        v2[i-2] += a + a;
    }
    return v2[1] >= x && v2[2] >= x;
}

void solve() {

    v.clear();
    v.push_back(0);
    minimum = mp(1e18, 0);

    cin >> n;
    int maximum = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        minimum = min(minimum, mp(v[i], i) );
    }
    int l = 1, r = *max_element(v.begin(), v.end());
    int ans = 0;
    while (l <= r) {
        //cerr << l << " " << r << "\n";
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
 
