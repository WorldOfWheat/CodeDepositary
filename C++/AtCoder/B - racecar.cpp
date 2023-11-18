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

int n;
VS arr;

bool isPalindrome(string str)
{
    int ptrL = 0;
    int ptrR = str.length() - 1;
    while (ptrL < ptrR)
    {
        if (str[ptrL] != str[ptrR])
        {
            return false;
        }
        ptrL++;
        ptrR--;
    }

    return true;
}

void solve()
{
    cin >> n;
    arr.resize(n, "");
    rep (i, 0, n)
    {
        cin >> arr[i];
    }

    rep (i, 0, n - 1)
    {
        rep (j, i + 1, n)
        {
            if (isPalindrome(arr[i] + arr[j]) || isPalindrome(arr[j] + arr[i]))
            {
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    cout << "No" << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
