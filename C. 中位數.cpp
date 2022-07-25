#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, less<int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 0; ; i++) {
        int n;
        cin >> n;
        if (n==0) break;
        if (i == 0) {
            pq.push(n);
            cout << n << "\n";
            continue;
        }
        if (n > pq.top())
            pq2.push(n);
        else
            pq.push(n);
        if (pq.size() > pq2.size()) {
            pq2.push(pq.top());
            pq.pop();
        }
        if (pq.size() < pq2.size()) {
            pq.push(pq2.top());
            pq2.pop();
        }
        if (pq.size() == pq2.size())
            cout << (pq.top() + pq2.top() ) / 2 << "\n";
        else {
            if (pq.size() > pq2.size())
                cout << pq.top() << "\n";
            else
                cout << pq2.top() << "\n";
        }
    }
    
    return 0;
}
