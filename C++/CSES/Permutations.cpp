
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln '\n'

using namespace std;

int n;
list<int> li;

void solve() {

    cin >> n;
    for (int i = 2; i <= n; i+=2) {
        li.push_back(i);
    }
    if (li.size() && li.back() - 1 <= 1) {
        cout << "NO SOLUTION" << ln;
        return;
    }
    for (int i = 1; i <= n; i+=2) {
        li.push_back(i);
    }
    for (auto a : li) {
        cout << a << " ";
    }
    cout << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
