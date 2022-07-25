#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            pq.push({b, a});
        }
        int print_time = 0;
        int times = 0;
        while (!pq.empty()) {
            print_time += pq.top().second;
            times = max(times, print_time + pq.top().first);
            pq.pop();
        }
        cout << times << endl;
    }

    return 0;
}
