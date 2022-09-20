#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
int o;
stringstream ss;

string cal(int x, int y) {
    if (y == 0) {
        return ss.str();
    }
    ss << x/m;
    if (y == o+1) {
        ss << ".";
    }
    return (cal((x%m)*10, y-1));
}

void solve() {

    while (cin >> n >> m >> o) {
        ss.str("");
        ss.clear();
        cout << cal(n, o+1) << endl;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
