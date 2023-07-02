// 第一段
#include <bits/stdc++.h>
#define MOD (int) 120322819

using namespace std;

int sum = 0;

void dfs(int start_number, int length_now, int total_length)
{
    if (length_now == total_length) 
    {
        sum++;
        sum %= MOD;
        return;
    }

    for (int i = start_number; i <= 9; i++)
    {
        dfs(i, length_now + 1, total_length);
    }
}

int main()
{
    int b;
    int n, m;
    string str;
    cin >> n >> m >> str;

    sum = 0;
    dfs(str.back() - '0', m, n);

    cout << sum << '\n';

    return 0;
}

// 第二段
#include <bits/stdc++.h>
#define MOD (int) 120322819

using namespace std;

vector<vector<int>> dp;

int dfs(int start_number, int start_length, int end_length)
{
    if (start_length == end_length) 
    {
        return 1;
    }
    if (dp[start_number][start_length] != 0)
    {
        return dp[start_number][start_length];
    }

    for (int i = 9; i >= start_number; i--)
    {
        dp[start_number][start_length] += dfs(i, start_length - 1, end_length);
        dp[start_number][start_length] %= MOD;
    }

    return dp[start_number][start_length];
}

int main()
{
    int f;
    int n, m;
    string str;
    cin >> n >> m >> str;

    dp.resize(9 + 1, vector<int>(n + 1));

    cout << dfs(str.back() - '0', n, m) << endl;

    return 0;
}

// 第三段
#include <bits/stdc++.h>
#define MOD (int) 120322819

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int g;
    int n, m;
    string str;
    cin >> n >> m >> str;

    vector<vector<int>> dp;
    dp.resize(10, vector<int>(n + 1));
    dp[str.back() - '0'][m] = 1;
    for (int i = str.back() - '0'; i <= 9; i++)
    {
        for (int j = m + 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }

    int sum = 0;
    for (int i = 1; i <= 9 ; i++)
    {
        sum += dp[i][n];
        sum %= MOD;
    }

    cout << sum << '\n';

    return 0;
}

