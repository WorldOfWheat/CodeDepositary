
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
    bitset<20> bs;
    int m = 0;
    int minimum = 2ll << 31;
    while (bs.count() < n) {
        m++;
        bs = m;
        int a = 0;
        int b = 0;
        for (int i = n; i >= 0; i--) {
            if (bs[i]) {
                a += v[i];
            } else {
                b += v[i];
            }
        }
        minimum = min(minimum, abs(a-b));
    }
    cout << minimum << endl;
    return 0;
}
