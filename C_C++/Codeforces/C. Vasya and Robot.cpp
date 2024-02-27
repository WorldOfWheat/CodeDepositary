#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;
string str;
int goal_x, goal_y;
int pf_x[(int) 2e5+1], pf_y[(int) 2e5+1];

bool check(int x) {
    for (int i = 1; i + x - 1 <= n; i++) {
        int r = i + x - 1;
        int a = pf_x[i-1] + (pf_x[n] - pf_x[r]);
        int b = pf_y[i-1] + (pf_y[n] - pf_y[r]);
        int c = abs(goal_x - a) + abs(goal_y - b);
        if (c <= x && (x-c) % 2 == 0) return true;
    }
    return false;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        pf_x[i] = pf_x[i-1];
        pf_y[i] = pf_y[i-1];
        switch (str[i-1]) {
            case 'U':
                pf_y[i]++;
                break;
            case 'D':
                pf_y[i]--;
                break;
            case 'R':
                pf_x[i]++;
                break;
            case 'L':
                pf_x[i]--;
                break;
        }
    }
    int l = 0, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid-1;
            ans = mid;
        } else {
            l = mid+1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> str >> goal_x >> goal_y;
    solve();

    return 0;
}
 
