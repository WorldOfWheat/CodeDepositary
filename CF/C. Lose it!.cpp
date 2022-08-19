#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
vector<int> ve2(6);

void discrete(vector<int> &x) {
    vector<int> order;
    order.assign(x.begin(), x.end());

    sort(order.begin(), order.end());
    order.erase( unique(order.begin(), order.end()), order.end() );

    for (auto it = x.begin(); it != x.end(); it++) {
        auto it2 = lower_bound(order.begin(), order.end(), *it);
        *it = distance(order.begin(), it2);
    }
}

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ve[i] = a;
    }

    discrete(ve);

    for (int i = 0; i < n; i++) {
        int top = ve[i];
        if (top == 0) {
            ve2[0]++;
        }
        else {
            if (ve2[top - 1] > 0) {
                ve2[top - 1]--;
                ve2[top]++;
            }
        }
    }
    cout << (n - ve2[5] * 6) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
