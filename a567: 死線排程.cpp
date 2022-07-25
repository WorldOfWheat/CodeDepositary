#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> d;
vector<int> p;


bool cmp(int a, int b) {
    return p[a] > p[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        d.clear();
        p.clear();
        int order[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
            int a, b;
            cin >> a >> b;
            d.push_back(a);
            p.push_back(b);
        }
        sort(order, order + sizeof(order)/sizeof(order[0]), cmp);
        int maximum_day = 0;
        for (auto a : d) {
            maximum_day = max(maximum_day, a);
        }
        int scd[maximum_day] = {0};
        int ans = 0;
        for (auto a : order) {
            int day = d[a]-1;
            while (true) {
                if (day < 0) break;
                if(scd[day]) {
                    day--;
                    continue;
                }
                scd[day] = p[a];
                ans += p[a];
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
