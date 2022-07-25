#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, h, dif;
    while (cin >> n >> h >> dif) {
        vector<int> cans;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            a /= h;
            cans.push_back(a);
            pq.push(make_pair(a, i));
        }
        int maxdif = dif/h;
        long long ans = 0;
        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            if (top.second -1 >= 0) {
                int l = top.second - 1;
                int d = cans[top.second]+maxdif;
                if (cans[l] > d) {
                    ans += cans[l] - d;
                    cans[l] = d;
                    pq.push(make_pair(cans[l], l));
                }
            }
            if (top.second + 1 < n) {
                int r = top.second + 1;
                if (cans[r] > cans[top.second]+maxdif) {
                    ans += cans[r] - (cans[top.second]+maxdif);
                    cans[r] = cans[top.second]+maxdif;
                    pq.push(make_pair(cans[r], r));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
