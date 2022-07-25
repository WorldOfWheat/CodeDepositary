#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
int arr[(int) 1e8+1];

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    map<int, int> ump;
    int ans = 0;
    int cnt = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        while (r <= n && cnt <= m) {
            r++;
            //cout << cnt << " " << arr[r] << " " << r << endl;
            ump[arr[r]]++;
            if (ump[arr[r]] == 1) {
                cnt++;
            }
            //cout << cnt << " " << arr[r] << " " << r << endl;
        }
        //cout << endl;
        //cout << r << " " << i << endl;
        ans += r - i;
        //cout << ans << endl << endl;
        ump[arr[i]]--;
        if (ump[arr[i]] == 0) {
            cnt--;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//離散化
//離散化
//離散化

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second
 
using namespace std;
__attribute__((optimize("-O3")))
 
int n, m;
int arr[(int) 1e8+1];
int arr2[(int) 1e8+1];
int visited[(int) 2e5+1];
 
void solve() {
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr2+1, arr2+n+1);
    for (int i = 1; i <= n; i++) {
        arr[i] = lower_bound(arr2+1, arr2+n+1, arr[i]) - arr2;
    }
    int ans = 0;
    int cnt = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        while (r <= n && cnt <= m) {
            r++;
            //cout << cnt << " " << arr[r] << " " << r << endl;
            visited[arr[r]]++;
            if (visited[arr[r]] == 1) {
                cnt++;
            }
            //cout << cnt << " " << arr[r] << " " << r << endl;
        }
        //cout << endl;
        //cout << r << " " << i << endl;
        ans += r - i;
        //cout << ans << endl << endl;
        visited[arr[i]]--;
        if (visited[arr[i]] == 0) {
            cnt--;
        }
    }
    cout << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}
 
