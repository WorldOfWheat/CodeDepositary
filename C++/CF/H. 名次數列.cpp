#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> v;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        multiset<int> ms;
        map<int, int> ma;
        queue<int> q;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            ms.insert(a);
            q.push(a);
        }
        int k = 1;
        for (auto a : ms) {
            if (ma[a] == 0) {
                ma[a] = k;
                k++;
            }
        }
        while (!q.empty()) {
            cout << ma[q.front()] << " ", q.pop();
        }
        cout << endl;
    }

    return 0;
}
