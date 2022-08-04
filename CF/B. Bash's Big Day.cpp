#include <bits/stdc++.h>
#define int long long

using namespace std;
__attribute__((optimize("-O3")))

int arr[100000+1];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;
        maxi = max(maxi, a);
    }
    int ans = 1;
    for (int i = 2; i <= maxi; i++) {
        int cnt = 0;
        for (int j = i; j <= maxi; j+=i) {
            cnt += arr[j];
        }
        if (cnt >= 2) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}
