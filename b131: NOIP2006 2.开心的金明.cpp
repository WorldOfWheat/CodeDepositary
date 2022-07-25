#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int maximum, n;
    cin >> maximum >> n;
    vector<pair<int, int>> items;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        items.push_back(make_pair(a, b));
    }
    long long room[n+1][maximum+1];
    memset(&room, 0, sizeof(room));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maximum; j++) {

            if (items[i-1].first > j) {
                room[i][j] = room[i-1][j];
                continue;
            }
            room[i][j] = max(room[i-1][j], (room[i-1][j-items[i-1].first])+(items[i-1].second*items[i-1].first) );

        }
    }
    cout << room[n][maximum] << endl;
    return 0;
}
