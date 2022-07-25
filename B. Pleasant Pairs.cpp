#include <bits/stdc++.h>
#define int long long

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = arr[i]-i; j <= n; j+=arr[i]) {
                if (j <= i ) continue;
                if (arr[i] * arr[j] == i + j) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
