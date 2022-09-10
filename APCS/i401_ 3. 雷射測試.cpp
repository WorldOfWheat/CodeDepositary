#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

set<int> se_x[(int) 3e4 + 1];
set<int> se_y[(int) 6e4 + 1];
map<pii, int> mp_status;

int n;
char dir = 'r';

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b += (int) 3e4;
        se_x[a].insert(b);
        se_y[b].insert(a);
        mp_status[mp(a, b)] = c;
    }
    int now_x = 0, now_y = (int) 3e4;
    int ans = 0;
    bool flag = true;
    while (flag) {
        switch (dir) {
            case 'u': {
                auto it = se_x[now_x].upper_bound(now_y);
                if (it == se_x[now_x].end()) {
                    flag = false;
                    break;
                }
                now_y = *it;
                ans++;
                if (mp_status[mp(now_x, now_y)] == 1) {
                    dir = 'l';
                }
                else {
                    dir = 'r';
                }
                break;
            }
            case 'd': {
                auto it = se_x[now_x].lower_bound(now_y);
                it--;
                if (distance(se_x[now_x].begin(), it) == -1) {
                    flag = false;
                    break;
                }
                now_y = *it;
                ans++;
                if (mp_status[mp(now_x, now_y)] == 1) {
                    dir = 'r';
                }
                else {
                    dir = 'l';
                }
                break;
            }
            case 'l': {
                auto it = se_y[now_y].lower_bound(now_x);
                it--;
                if (distance(se_y[now_y].begin(), it) == -1) {
                    flag = false;
                    break;
                }
                now_x = *it;
                ans++;
                if (mp_status[mp(now_x, now_y)] == 1) {
                    dir = 'u';
                }
                else {
                    dir = 'd';
                }
                break;
            }
            case 'r': {
                auto it = se_y[now_y].upper_bound(now_x);
                if (it == se_y[now_y].end()) {
                    flag = false;
                    break;
                }
                now_x = *it;
                ans++;
                if (mp_status[mp(now_x, now_y)] == 1) {
                    dir = 'd';
                }
                else {
                    dir = 'u';
                }
                break;
            }
        }
    }
    cout << ans << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
