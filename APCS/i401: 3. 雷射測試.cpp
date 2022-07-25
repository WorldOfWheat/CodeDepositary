#include <iostream>
#include <algorithm>
#include <vector>
#define pa1 pair<int, int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n) {
        vector<pa1> mx[30000+1];
        vector<pa1> my[60000+1];
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            b += 30000;
            mx[a].push_back({b, c});
            my[b].push_back({a, c});
        }
        for (auto &a : mx) sort(a.begin(), a.end());
        for (auto &a : my) sort(a.begin(), a.end());

        char d = 'r';
        int x = 0;
        int y = 30000;
        int c = 0;
        while (true) {
            if (d == 'r') {
                auto it = upper_bound(my[y].begin(), my[y].end(), make_pair(x, 1));
                if (it == my[y].end()) break;
                auto a = *it;
                x = a.first;
                d = (a.second == 0) ? 'u' : 'd';
            } else
            if (d == 'l') {
                auto it = lower_bound(my[y].begin(), my[y].end(), make_pair(x, 0));
                if (it == my[y].begin()) break;
                it--;
                auto a = *it;
                x = a.first;
                d = (a.second == 0) ? 'd' : 'u';
            } else
            if (d == 'u') {
                auto it = upper_bound(mx[x].begin(), mx[x].end(), make_pair(y, 1));
                if (it == mx[x].end()) break;
                auto a = *it;
                y = a.first;
                d = (a.second == 0) ? 'r' : 'l';
            } else
            if (d == 'd') {
                auto it = lower_bound(mx[x].begin(), mx[x].end(), make_pair(y, 0));
                if (it == mx[x].begin()) break;
                it--;
                auto a = *it;
                y = a.first;
                d = (a.second == 0) ? 'l' : 'r';
            }
            c++;
        }
        cout << c << endl;
    }

    return 0;
}
