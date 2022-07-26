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
    //
    if (n == 1) {
        cout << (m == ve[1]) << endl;
        return;
    }
    int mid = n/2;
    bitset<20+1> bs;
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
        ve_left.push_back(sum);
    }
    bitset<20+1> bs2;
    k = 0;
    while (bs2.count() != mid+n%2) {
        bs2 = k;
        k++;
        int sum = 0;
        for (int i = mid+1; i <= n; i++) {
            if (bs2[i-mid-1]) {
                sum += ve[i];
            }
        }
        ve_right.push_back(sum);
    }
    //
    sort(ve_right.begin(), ve_right.end());
    int ans = 0;
    for (auto a : ve_left) {
        int remain = m - a;
        auto it = lower_bound(ve_right.begin(), ve_right.end(), remain);
        auto it2 = upper_bound(ve_right.begin(), ve_right.end(), remain);
        ans += distance(it, it2);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n, m;
vector<int> ve;
vector<int> ve_left;
vector<int> ve_right;

void solve () {

    cin >> n >> m;
    int mid = (n >> 1);
    ve.resize(n+1);
    for (int i = 1 ; i <= n; i++) {
        cin >> ve[i];
    }
    for (int i = 0; i < (1 << mid); i++) {
        int sum = 0;
        for (int j = 0; j < mid; j++) {
            if (i & (1 << j)) {
                //cerr << ve[j+1] << " ";
                sum += ve[j+1];
            }
        }
        //cerr << "\n";
        ve_left.push_back(sum);
    }
    for (int i = 0; i < (1 << (mid + (n%2)) ); i++) {
        int sum = 0;
        for (int j = 0; j < mid + (n%2); j++) {
            if (i & (1 << j)) {
                //cerr << ve[j+mid+1] << " ";
                sum += ve[j+mid+1];
            }
        }
        //cerr << "\n";
        ve_right.push_back(sum);
    }

    sort(ve_left.begin(), ve_left.end());
    sort(ve_right.begin(), ve_right.end());
    int ans = 0;
    for (auto a : ve_left) {
        auto it = lower_bound(ve_right.begin(), ve_right.end(), m - a);
        auto it2 = upper_bound(ve_right.begin(), ve_right.end(), m - a);
        ans += distance(it, it2);
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
