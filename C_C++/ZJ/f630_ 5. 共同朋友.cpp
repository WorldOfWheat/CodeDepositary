#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<bitset<2500+1> > v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bitset<2500+1> bs;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            bs[a] = 1;
        }
        v.push_back(bs);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((v[i] & v[j]).any()) sum++;
        }
    }
    cout << sum << endl;

    return 0;
}
