#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        if (m == 1) {
            cout << "NO" << "\n";
            continue;
        }
        bool flag = false;
        for (int i = 1; i*i*i <= m; i++) {
            int a = i;
            int b = m - a*a*a;
            int temp = cbrt(b);
            if (temp*temp*temp != b || temp == 0) {
                continue;
            }
            if (a*a*a + b == m) {
                flag =  true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}
