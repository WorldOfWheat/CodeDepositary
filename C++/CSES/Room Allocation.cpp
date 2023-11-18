#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

struct customer {
    int arrive;
    int departure;
    int index;
};

bool cmp(customer x, customer y) {
    return x.arrive < y.arrive;
}

int n;
vector<customer> ve;
vector<int> table;

void solve() {

    cin >> n;
    ve.resize(n);
    table.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].arrive >> ve[i].departure;
        ve[i].index = i;
    }

    sort(ve.begin(), ve.end(), cmp);

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (pq.empty() || pq.top().F >= ve[i].arrive) {
            k++;
            pq.push({ve[i].departure, k});
            table[ve[i].index] = k;
        }
        else {
            pii top = pq.top();
            pq.pop();
            table[ve[i].index] = top.S;
            pq.push({ve[i].departure, top.S});

        }
    }

    cout << k << "\n";
    for (int i = 0; i < n; i++) {
        cout << table[i] << " ";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
