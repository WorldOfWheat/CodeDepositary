#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

int n;
multiset<int> ms;

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto it = ms.upper_bound(a);
        ms.insert(a);
        if (it == ms.end()) {
            continue;
        }
        ms.erase(it);
    }
    cout << ms.size() << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
