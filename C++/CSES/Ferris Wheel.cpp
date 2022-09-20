#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n, m;
multiset<int> ms;

void solve () {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ms.insert(a);
    }

    /*for (auto a : ms) {
        cerr << a << " ";
    }
    cerr << "\n";*/

    int ans = 0;

    while (ms.size()) {

        /*for (auto a : ms) {
            cerr << a << " ";
        }
        cerr << "\n";*/

        int top = *ms.begin();
        int remain = m - top;

        auto it = ms.upper_bound(remain);
        ans++;
        if (it != ms.begin()) {
            it--;
            //cerr << (*it) << " ";
            if (it == ms.begin()) {
                ms.erase(it);
                continue;
            }
            ms.erase(it);
            ms.erase(ms.begin());
            continue;
        }
        ms.erase(ms.begin());
    }

    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
