#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    stringstream ss;
    bool flag = true;
    int k = 0;
    while (flag) {
        flag = false;
        for (auto a : v) {
            if (k < a.size()) {
                if (isalpha(a[k])) ss << a[k];
                flag = true;
            }
        }
        k++;
    }
    cout << ss.str() << endl;

    return 0;
}
