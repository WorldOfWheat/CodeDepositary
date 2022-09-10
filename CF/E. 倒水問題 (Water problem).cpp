#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    int minimum = 2LL << 31;
    int ans_1 = 0, ans_2 = 0;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            int temp = (i*a + j*b);
            if (n - temp >= m) {
                if (minimum >= n-temp-m) {
                    ans_1 = i;
                    ans_2 = j;
                    minimum = n-temp-m;
                }
            }
        }
    }
    cout << ans_1 << " " << ans_2 << " " << minimum << endl;
    return 0;
}
