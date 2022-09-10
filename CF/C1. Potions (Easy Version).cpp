#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

void solve() {

    int n;
    cin >> n;
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        int top;
        cin >> top;
        if (top >= 0) {
            ans++;
            now += top;
        }
        else if (now + top >= 0) {
            ans++;
            now += top;
            pq.push(abs(top));
        }
        else if (pq.size() && abs(top) < pq.top()) {
            now += pq.top() + top;
            pq.pop();
            pq.push(abs(top));
        }
    }
    cout << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
