#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> s;
    vector<int> v;
    s.insert(1);
    while (v.size() != 1500) {
        int num = *s.begin();
        s.insert(num*2);
        s.insert(num*3);
        s.insert(num*5);
        s.erase(*s.begin());
        v.push_back(num);
    }
    cout << "The 1500'th ugly number is " << v.back() << "." << endl;
    return 0;
}
