#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> go;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; 
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    go.resize(n + 1, vector<int>(61));
    for (int i = 1; i <= n; i++)
    {
        go[i][0] = arr[i]; 
    }
    for (int j = 1; j < 61; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            go[i][j] = go[go[i][j-1]][j-1];
        }
    }

    m--;
    int pos = 1;
    for (int i = 0; i < 60; i++)
    {
        if ((m >> i) & 1)
        {
            pos = go[pos][i];
        }
    }
    cout << pos << '\n';

    return 0;
}
