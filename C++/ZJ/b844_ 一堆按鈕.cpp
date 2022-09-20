#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    while (cin >> n >> q) {
        vector<int> v;
        while (n--) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), less<int>());
        while (q--) {
            int a;
            cin >> a;
            auto it = upper_bound(v.begin(), v.end(), a);
            cout << (it-v.begin()) % 2 << endl;
        }
    }

    return 0;
}
