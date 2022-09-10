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

void solve() {

    cin >> n;
    int k = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (i == 1) {
            k = a;
            ans = a;
            continue;
        }
        k = max((int) a, k+a);
        ans = max(ans, k);
    }
    cout << ans << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

int _merge(int l, int r) {
    if (l == r) {
        return ve[l];
    }
    int mid = (l + r) / 2;
    int maxi = max(_merge(l, mid), _merge(mid+1, r));
    int maxi_left = ve[mid];
    int maxi_right = ve[mid+1];
    int sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += ve[i];
        maxi_left = max(maxi_left, sum);
    }
    sum = 0;
    for (int i = mid+1; i <= r; i++) {
        sum += ve[i];
        maxi_right = max(maxi_right, sum);
    }
    return (max(maxi, maxi_left + maxi_right));
}

void solve() {

    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }

    cout << (_merge(0, ve.size() - 1)) << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
