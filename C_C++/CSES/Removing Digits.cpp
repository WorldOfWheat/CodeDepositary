#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> dp;

int cal(int x)
{
    // cerr << x << '\n';
    if (x <= 9) return 1;
    if (dp[x] != 0) return dp[x];
    
    int lsb = x;
    int minimum = 1e9;
    while (lsb > 0)
    {
        int sub_num = lsb % 10;
        if (sub_num != 0) minimum = min(cal(x - sub_num), minimum);
        lsb /= 10;
    }
    
    return dp[x] = minimum + 1;
}

void solve()
{
    cin >> n;   

    dp.resize(n + 1);
    
    cout << cal(n) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

// #####################################################################

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n;
vi dp;

void solve() 
{
    cin >> n;
    
    dp.resize(max(n+1, 10), 1e9);
    for (int i = 0; i <= 9; i++) dp[i] = 1;
    
    for (int i = 10; i <= n; i++) 
    {
        int divisor = i;
        while (divisor > 0) 
        {
            if (divisor % 10 == 0) 
            {
                divisor /= 10;
                continue;
            }
            dp[i] = min(dp[i-(divisor % 10)] + 1, dp[i]);
            divisor /= 10;
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

