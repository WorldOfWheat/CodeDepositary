#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, h, r;
    vector<pii> v;
    set<int> s;
    while (cin >> l >> h >> r) {
        if (l == r) continue;
        v.push_back(make_pair(r, -h));
        v.push_back(make_pair(l, h));
    }
    sort(v.begin(), v.end(), [](pii x, pii y) {return x.first < y.first || (x.first == y.first && x.second > y.second); } );
    multiset<int> ms;
    int last = -1;
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].first;
        int b = v[i].second;
        if (b > 0) {
            ms.insert(b);
        } else {
            if (ms.count(-b)) ms.erase(ms.find(-b));
        }
        if (ms.empty()) {
            cout << a << " 0 ";
            last = -1;
            continue;
        }
        if (last == -1) {
            cout << a << " " << *ms.rbegin() << " ";
        } else {
            if (last != *ms.rbegin()) {
                cout << a << " " << *ms.rbegin() << " ";
            }
        }
        last = *ms.rbegin();
    }
    cout << endl;

    return 0;
}
