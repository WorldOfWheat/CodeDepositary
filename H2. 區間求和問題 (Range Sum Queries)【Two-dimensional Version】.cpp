#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int num[n][m];
    for (auto &a : num) {
        for (auto &b : a) {
            cin >> b;
        }
    }
    int sum[n+1][m+1];
    memset(&sum, 0, sizeof(sum));
    sum[1][1] = num[0][0];
    for (int i = 1; i < n; i++) {
        sum[i+1][1] = sum[i][1] + num[i][0];
    }
    for (int i = 1; i < m; i++) {
        sum[1][i+1] = sum[1][i] + num[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            sum[i+1][j+1] = num[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c++;
        d++;
        cout << sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b] << endl;
    }

    return 0;
}
