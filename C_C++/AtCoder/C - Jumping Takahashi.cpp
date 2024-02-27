#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bitset<10001> bs(1);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        bs = (bs << a) | (bs << b);
    }
    cout << (bs[m] ? "Yes" : "No") << endl;

    return 0;
}
