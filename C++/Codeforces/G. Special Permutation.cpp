#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        if (m <= 3) {
            cout << -1 << endl;
            continue;
        }
        if (m == 4) {
            cout << "2 4 1 3" << endl;
            continue;
        }
        deque<int> dq;
        dq.push_back(2);
        dq.push_back(4);
        dq.push_back(1);
        dq.push_back(3);
        for (int i = 5; i <= m; i+=2) {
            dq.push_front(i);
        }
        for (int i = 6; i <= m; i+=2) {
            dq.push_back(i);
        }
        stringstream ss;
        while (!dq.empty()) {
            ss << dq.front() << " ";
            dq.pop_front();
        }
        cout << ss.str() << endl;
    }

    return 0;
}
