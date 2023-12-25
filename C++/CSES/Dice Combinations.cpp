#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
int n;
vector<int> record(1e6 + 1);

int f(int x)
{
    if (x == 0) return 1;
    if (record[x]) return record[x];

    int sum = 0;
    for (int i = 1; i <= min(6, x); i++)
    {
        sum += f(x - i);
        sum %= MOD;
    }

    return record[x] = sum;
} 

void solve()
{
    cin >> n;
    cout << f(n) << '\n';
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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
int n;
vector<int> dp(1e6 + 1);

void solve()
{
    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= min(i, 6); j++)
        {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    
    cout << dp[n] << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}