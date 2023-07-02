#include <bits/stdc++.h>
#define int long long
#define VS vector<string>
#define V vector<int>
#define VV vector<V>
#define VP vector<PII>
#define VVP vector<VP>
#define PII pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define nl '\n';
#define INF (int) 1e18
#define MOD (int) 1e9 + 7

using namespace std;

int n, m;
map<int, int> ma;

void solve()
{
    cin >> n >> m;
    rep (i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        ma[a]++;
        ma[b]--;
    }

    int ans = 0;
    int now = 0;
    int last = ma.begin()->F;
    for (auto it = ma.begin(); it != ma.end(); it = next(it))
    {
        ans += (it->F - last) * min(now, m);
        last = it->F;
        now += it->S;
    }

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
