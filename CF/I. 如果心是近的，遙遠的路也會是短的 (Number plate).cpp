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

    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    int n;
    cin >> n;

    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    vector<pii> T;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (v2[i] - v[j] < 0) continue;
            T.push_back(mp(v2[i] - v[j], i));
        }
    }
    sort(T.begin(), T.end());
    /*for (auto a : T) {
        cout << a.F << " " << a.S << endl;
    }*/
    set<int> se;
    int l = 0, r = 0;
    se.insert(T[0].S);
    int mark[n] = {0};
    mark[T[0].S]++;
    int ans = 1e18;

    while (l < T.size()) {
        while (se.size() != n && r < T.size()) {
            r++;
            if (r == T.size()) break;
            se.insert(T[r].S);
            mark[T[r].S ]++;
        }
        if (se.size() == n) {
            int a = T[r].F - T[l].F;
            ans = min(ans, a);
            if (mark[T[l].S] == 1) {
                se.erase(T[l].S);
            }
            mark[T[l].S]--;
            l++;
        } else {
            break;
        }
    }

    cout << ans <<endl;

    return 0;
}
 
