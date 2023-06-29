#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18

using namespace std;

int n;
V arr;

void solve()
{
    cin >> n;
    arr.resize(n);
    int counter = 0;
    rep (i, 0, 7 * n)
    {
        int in;
        cin >> in;
        arr[i / 7] += in;
    }

    rep (i, 0, n)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
