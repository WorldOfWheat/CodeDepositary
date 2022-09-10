#include <bits/stdc++.h>
#define int long long
#define db(a) cout << a << endl
#define tp tuple<int, int, int>

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    tp arr[n];
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = make_tuple(a, b, c);
    }
    bitset<3> bs;
    int maxi = 0;
    for (int k = 0; bs.count() < 3; k++) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            bs = k;
            int sum = 0;
            int a = get<0>(arr[i]);
            int b = get<1>(arr[i]);
            int c = get<2>(arr[i]);
            if (bs[0]) {
                sum += a;
            } else {
                sum -= a;
            }
            if (bs[1]) {
                sum += b;
            } else {
                sum -= b;
            }
            if (bs[2]) {
                sum += c;
            } else {
                sum -= c;
            }
            v.push_back(sum);
        }
        int sum = 0;
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < m; i++) {
            sum += v[i];
        }
        maxi = max(maxi, sum);
    }
    cout << maxi << "\n";

    return 0;
}
