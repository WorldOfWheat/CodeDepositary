#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int main() {
    int n, m, l, q;
    cin >> n >> m >> l >> q;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    set<int> fake;
    for (int i = 0; i < l; i++) {
        int x;
        cin >> x;
        fake.insert(x);
    }
    vector<int> data;
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        data.push_back(y);
    }
    for (int a : data) {
        while (true) {
            if (fake.count(a)) {
                cout << "TUIHUOOOOOO";
                break;
            }
            if (graph[a].size() == 0) {
                cout << "YA~~";
                break;
            }
            a = graph[a][0];
        }
        cout << endl;
    }
    return 0;
}
