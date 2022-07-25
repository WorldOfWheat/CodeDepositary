#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int maximum = 0;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            maximum = max(maximum, a);
        }
        v.push_back(maximum);
    }
    int sum = 0;
    for (auto a : v) sum += a;
    cout << sum << endl;
    stringstream ss;
    bool flag = true;
    for (auto a : v) {
        if (sum % a == 0) {
            ss << a << " ";
            flag = false;
        }
    }
    if (flag)
        cout << -1;
    else {
        string ans = ss.str();
        ans.pop_back();
        cout << ans << endl;
    }
    return 0;
}
