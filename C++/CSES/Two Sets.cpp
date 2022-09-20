#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln '\n'

using namespace std;

int n;
set<int> se;
set<int> se2;

void solve() {

    cin >> n;
    int sum = ((1 + n) * n) >> 1;
    if (sum % 2) {
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;
    int mid = sum >> 1;
    int temp = n;
    for (int i = 1; i <= n; i++) {
        se.insert(i);
    }
    while (!se.count(mid)) {
        mid -= temp;
        se2.insert(temp);
        se.erase(temp);
        temp--;
    }
    se.erase(mid);
    se2.insert(mid);
    cout << (se.size()) << ln;
    for (auto a : se) {
        cout << a << " ";
    }
    cout << ln;
    cout << (se2.size()) << ln;
    for (auto a : se2) {
        cout << a << " ";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
