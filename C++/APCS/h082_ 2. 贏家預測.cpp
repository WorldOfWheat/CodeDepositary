#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

struct player {
    int power_a;
    int power_b;
    int index;
    int loss;
};

int n, m;
vector<player> ve;
list<int> li;

int dfs(list<int> x) {
    if (x.size() == 1) {
        return (ve[x.front()].index);
    }
    list<int> li_win;
    list<int> li_lost;
    while (!x.empty()) {

        player &p1 = ve[x.front()];
        x.pop_front();
        if (x.empty()) {
            li_win.push_back(p1.index - 1);
            break;
        }
        player &p2 = ve[x.front()];
        x.pop_front();

        int a = p1.power_a;
        int b = p1.power_b;
        int c = p2.power_a;
        int d = p2.power_b;

        if (a * b >= c * d) {
            p1.power_a = a + c*d / (2*b);
            p1.power_b = b + c*d / (2*a);
            p2.power_a = c + c/2;
            p2.power_b = d + d/2;

            li_win.push_back(p1.index-1);
            p2.loss++;
            if (p2.loss < m) {
                li_lost.push_back(p2.index-1);
            }
        }
        else {
            p2.power_a = c + a*b / (2*d);
            p2.power_b = d + a*b / (2*c);
            p1.power_a = a + a/2;
            p1.power_b = b + b/2;

            li_win.push_back(p2.index-1);
            p1.loss++;
            if (p1.loss < m) {
                li_lost.push_back(p1.index-1);
            }
        }
    }
    x.clear();
    x.insert(x.end(), li_win.begin(), li_win.end());
    x.insert(x.end(), li_lost.begin(), li_lost.end());
    return dfs(x);
}

void solve() {

    cin >> n >> m;
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].power_a;
        ve[i].index = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> ve[i].power_b;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        li.push_back(a-1);
    }
    cout << (dfs(li)) << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
