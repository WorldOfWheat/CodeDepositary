
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<int> v;
    multiset<int> ms;
    multiset<int> ms2;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int num = v[i];
        q.push(num);
        if (i==0) {
            ms.insert(num);
        } else {
            if (num > *ms.rbegin()) {
                ms2.insert(num);
            } else {
                ms.insert(num);
            }
            if (ms.size() > ms2.size()) {
                ms2.insert(*ms.rbegin());
                ms.erase(ms.find(*ms.rbegin()));
            }
            if (ms.size() < ms2.size()) {
                ms.insert(*ms2.begin());
                ms2.erase(ms2.find(*ms2.begin()));
            }
        }
    }
    for (int i = m; i <= n; i++) {
        if (ms.size() == ms2.size()) {
            cout << ( *ms.rbegin() > *ms2.begin() ? *ms2.begin() : *ms.rbegin() ) << " ";
        } else {
            if (ms.size() > ms2.size()) {
                cout << *ms.rbegin() << " ";
            } else {
                cout << *ms2.begin() << " ";
            }
        }
        int f = q.front();
        if (ms.count(f)) {
            ms.erase(ms.find(f));
        } else {
            ms2.erase(ms2.find(f));
        }
        int num = v[i];
        q.push(num);
        q.pop();
 
        if (num < *ms2.begin()) {
            ms.insert(num);
        } else {
            ms2.insert(num);
        }
        if (ms.size() > ms2.size()) {
            ms2.insert(*ms.rbegin());
            ms.erase(ms.find(*ms.rbegin()));
        }
        if (ms.size() < ms2.size()) {
            ms.insert(*ms2.begin());
            ms2.erase(ms2.find(*ms2.begin()));
        }
 
    }
    cout << endl;
    return 0;
}
