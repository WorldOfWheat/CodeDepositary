#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<int> table((int) 1e6+1);

void init() {

    for (int i = 1; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j+=i) {
            table[j]++;
        }
    }
}

void solve() {

    cin >> n;
    cout << table[n] << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

