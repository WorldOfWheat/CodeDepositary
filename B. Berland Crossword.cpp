#include <bits/stdc++.h>
#define int long long
#define P(a) cout << a << endl

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bitset<4> bs;
        bool flag = true;
        for (int i = 0; bs.count() < 4; i++) {
            bs = i;
            int A = bs[0] + bs[1];
            int B = bs[1] + bs[2];
            int C = bs[2] + bs[3];
            int D = bs[3] + bs[0];
            if (
                ( (A <= u) && (u <= A + (n-2)) ) &&
                ( (B <= r) && (r <= B + (n-2)) ) &&
                ( (C <= d) && (d <= C + (n-2)) ) &&
                ( (D <= l) && (l <= D + (n-2)) )
            ) {
                cout << "YES" << "\n";
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
