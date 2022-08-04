#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> sum;
    sum.push_back(0);
    for (int i = 0; i < n; i++) {
        sum.push_back(sum[i] + v[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b]-sum[a-1] << endl;
    }
    return 0;
}
