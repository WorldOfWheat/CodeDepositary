#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (m--) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        cost += a + b;
    }
    cout << cost << endl;
    return 0;
}
