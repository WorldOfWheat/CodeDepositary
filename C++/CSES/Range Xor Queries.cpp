#include <bits/stdc++.h>
#define int long long
#define VS vector<string>
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

int n, m;
V arr;
V prefixXor;

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    prefixXor.resize(n + 1);
    for (auto &i : arr)
    {
        cin >> i;
    }

    rep2 (i, 1, n)
    {
        prefixXor[i] = prefixXor[i-1] ^ arr[i-1];
    }
    rep (i, 0, m)
    {
        int left, right;
        cin >> left >> right;
        cout << (prefixXor[right] ^ prefixXor[left - 1]) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
