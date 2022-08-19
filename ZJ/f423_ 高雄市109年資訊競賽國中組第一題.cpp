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
    int sum = 0;
    for (int i = 1; i <= n; i+=2) {
        sum += i;
    }
    cout << sum << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
