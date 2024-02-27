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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int maxi = -2ll << 31;
        for (int i = max(0ll, n-2*k-1); i < n; i++) {
            for (int j = i+1; j < n; j++) {
                maxi = max(maxi, (i+1)*(j+1)-k*(arr[i] | arr[j]) );
            }
        }
        cout << maxi << "\n";
    }

    return 0;
}
