#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;
vector<int> ve;

bool cmp(int x, int y) {
    int a = (x % 10);
    int b = (y % 10);
    if (a < b) {
        return 1;
    }
    if (a > b) {
        return 0;
    }
    if (a == b) {
        return (x > y);
    }
}

void solve() {

    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end(), cmp);
    for (auto a : ve) {
        cout << a << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
