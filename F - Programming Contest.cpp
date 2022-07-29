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
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    if (n == 1) {
        if (ve[1] <= m) {
            cout << ve[1] << endl;
            return;
        } else {
            cout << 0 << endl;
            return;
        }
    }
    int mid = n / 2;
    bitset<40/2+1> bs;
    int k = 0;
    while (bs.count() != mid) {
        bs = k;
        int sum = 0;
        for (int i = 1; i <= mid; i++) {
            //cout << bs[i-1];
            if (bs[i-1]) {
                sum += ve[i];
            }
        }
        //cout << endl;
        ve_left.push_back(sum);
        k++;
    }
    bitset<40/2+1> bs2;
    k = 0;
    while (bs2.count() != mid+n%2) {
        bs2 = k;
        int sum = 0;
        for (int i = 1; i <= mid+n%2; i++) {
            //cout << bs2[i-1];
            if (bs2[i-1]) {
                sum += ve[i+mid];
            }
        }
        //cout << endl;
        ve_right.push_back(sum);
        k++;
    }
    /*for (auto a : ve_left) {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : ve_right) {
        cout << a << " ";
    }
    cout << endl;*/
    sort(ve_right.begin(), ve_right.end());
    int ans = 0;
    for (auto a : ve_left) {
        int remain = m - a;
        auto it = upper_bound(ve_right.begin(), ve_right.end(), remain);
        //cout << distance(ve_right.begin(), it) << endl;
        it--;
        if (distance(ve_right.begin(), it) == -1) continue;
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
