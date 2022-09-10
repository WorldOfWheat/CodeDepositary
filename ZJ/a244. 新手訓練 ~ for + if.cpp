#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;
vector<int> ve;

void solve() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1:
                cout << b+c << "\n";
                break;
            case 2:
                cout << b-c << "\n";
                break;
            case 3:
                cout << b*c << "\n";
                break;
            case 4:
                cout << b/c << "\n";
                break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
