
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << endl
#define mp(x, y) make_pair(x, y)
#define F first
#define S second
 
using namespace std;
__attribute__((optimize("-O3")))
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    pii arr[n+1];
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr[i] = mp(a, i);
    }
    sort(arr, arr+n+1, less<pii>());
    int l = 1;
    int r = n;
    int now = 0;
    bool flag = true;
    while (l < r) {
        now = arr[l].F+arr[r].F;
        if (now == m) {
            cout << min(arr[l].S, arr[r].S) << " " << max(arr[l].S, arr[r].S) << endl;
            r--;
            flag = false;
        }
        if (now < m) {
            l++;
        }
        if (now > m) {
            r--;
        }
    }
    if (flag) {
        cout << "IMPOSSIBLE" << endl;
    }
 
    return 0;
}
 
