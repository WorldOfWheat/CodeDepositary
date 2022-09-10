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
vector<int> ve;
vector<int> ve_left;
vector<int> ve_right;

void solve() {

    cin >> n >> m;
    ve.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    if (n == 1) {
        cout << (ve[1] % m) << endl;
        return;
    }
    int mid = n / 2;
    bitset<40/2+1> bs;
    int k = 0;
    while (bs.count() != mid) {
        bs = k;
        k++;
        int sum = 0;
        for (int i = 0; i < mid; i++) {
            if (bs[i]) {
                sum += ve[i+1];
            }
        }
        ve_left.push_back(sum % m);
    }
    bs = 0;
    k = 0;
    while (bs.count() != mid+n%2) {
        bs = k;
        k++;
        int sum = 0;
        for (int i = 0; i < mid+n%2; i++) {
            if (bs[i]) {
                sum += ve[i+1+mid];
            }
        }
        ve_right.push_back(sum % m);
    }
    sort(ve_left.begin(), ve_left.end());
    sort(ve_right.begin(), ve_right.end());
    /*for (auto a : ve_left) {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : ve_right) {
        cout << a << " ";
    }
    cout << endl;*/
    int ans = -1e18;
    for (auto a : ve_left) {
        int remain = m - a;
        auto it = lower_bound(ve_right.begin(), ve_right.end(), remain);
        it--;
        //cout << (distance(it, ve_right.begin())) << endl;
        if (distance(ve_right.begin(), it) == -1) continue;
        if (*it + a >= m) continue;
        ans = max(ans, *it + a);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
