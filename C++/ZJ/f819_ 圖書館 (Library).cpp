#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b > 100)
            v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (auto a : v) {
        cout << a.first << " ";
        sum += (a.second - 100)*5;
    }
    cout << endl << sum << endl;


    return 0;
}
