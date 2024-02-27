#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int n, m;
vector<int> arr;
vector<int> record(1e6 + 1);

int f(int x) 
{
    if (x < 0) return 1e9;
    if (x == 0) return 1;
    if (record[x] != 0) return record[x];

    int res = 1e9;    
    for (int i = 0; i < n; i++)
    {
        res = min(res, f(x - arr[i]) + 1);
    }
    
    return record[x] = res;
}

void solve()
{
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = f(m);
    if (ans == 1e9) cout << "-1\n";
    else cout << ans - 1 << "\n";
}

int main()
{
    fastio;

    solve();

    return 0;
}

/* ####################################################################################### */

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
vector<int> dp(1e6 + 1, 1e9);

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        dp[arr[i]] = 1
    }

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
    }
    
    if (dp[m] == 1e9) cout << "-1\n";
    else cout << dp[m] << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}