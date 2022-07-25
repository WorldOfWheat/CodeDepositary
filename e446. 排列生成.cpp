#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++) {
        m[i] = i+1;
    }
    do {
        for (auto a : m) {
            cout << a << " ";
        }
        cout << "\n";
    } while(next_permutation(m, m+n));

    return 0;
}
