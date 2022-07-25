
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
 
int n, m;
pii arr[5000+1];
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr[i] = mp(a, i);
    }
    sort(arr, arr+n+1, less<pii>());
    bool flag = true;
    for (int i = 2; i <= n-1; i++) {
        int temp = m - arr[i].F;
        int l = 1;
        int r = n;
        while (l < r) {
            if (arr[l].F+arr[r].F == temp) {
                flag = false;
                int a[3] = {arr[l].S, arr[i].S, arr[r].S};
                sort(a, a+3);
                cout << a[0] << " " << a[1] << " " << a[2] << endl;
            }
            int a = arr[l].F + arr[r].F;
            if (l + 1 != i && a < temp) {
                l++;
            } else
            if (r - 1 != i && a > temp) {
                r--;
            } else
                break;
        }
    }
    if (flag) {
        cout << "IMPOSSIBLE" << endl;
    }
 
    return 0;
}
 
