#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        vector<int> s;
        vector<int> t;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            t.push_back(a);
        }
        vector<int> order;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            order.push_back(a-1);
        }
        int lost[n] = {0};
        vector<int> win;
        vector<int> loss;
        while (order.size() > 1) {
            for (int i = 1; i <= order.size()-1; i+=2) {
                int p1 = order[i-1];
                int p2 = order[i];
                int a = s[p1];
                int b = t[p1];
                int c = s[p2];
                int d = t[p2];
                if (a*b >= c*d) {
                    s[p1] = a + c*d/(2*b);
                    t[p1] = b + c*d/(2*a);
                    s[p2] = c + c/2;
                    t[p2] = d + d/2;
                    win.push_back(order[i-1]);
                    lost[p2]++;
                    if (lost[p2] < m) loss.push_back(order[i]);
                } else {
                    s[p2] = c + a*b/(2*d);
                    t[p2] = d + a*b/(2*c);
                    s[p1] = a + a/2;
                    t[p1] = b + b/2;
                    win.push_back(order[i]);
                    lost[p1]++;
                    if (lost[p1] < m) loss.push_back(order[i-1]);
                }
            }
            if (order.size() % 2 != 0) win.push_back(order[order.size()-1]);
            order.clear();
            for (auto a : win) order.push_back(a);
            for (auto a : loss) order.push_back(a);
            win.clear();
            loss.clear();
        }
        cout << order[0]+1 << endl;
    }
    return 0;
}
