#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;

void solve() {

    cin >> n;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << (last + a) << " ";
        last += a;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
