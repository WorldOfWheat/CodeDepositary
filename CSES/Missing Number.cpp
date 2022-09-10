#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n;
set<int> se;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        se.insert(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        se.erase(a);
    }
    for (auto a : se) {
        cout << a << " ";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
