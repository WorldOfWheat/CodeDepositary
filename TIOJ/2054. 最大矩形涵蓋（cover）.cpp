#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, h, w;
vector<pii> ve;

void solve() {

    cin >> n >> h >> w;
    ve.push_back(mp(-1, -1));
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        ve.push_back(mp(a, b));
    }
    sort(ve.begin(), ve.end(), less<pii>());
    /*cout << endl;
    for (auto a : ve) {
        cout << a.F << " " << a.S << endl;
    }
    cout << endl;*/
    int l = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (ve[i].F - ve[l].F > w) {
            l++;
        }
        vector<pii> temp;
        for (int j = l; j <= i; j++) {
            //cout << ve[j].F << " " << ve[j].S << endl;
            temp.push_back(mp(ve[j].S, ve[j].F));
        }
        sort(temp.begin(), temp.end(), less<pii>());
        int cnt = 0;
        int l2 = 0;
        for (int j = 0; j < temp.size(); j++) {
            while (temp[j].F - temp[l2].F > h) {
                l2++;
            }
            ans = max(ans, j-l2+1);
        }
    }
    cout << ans <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
