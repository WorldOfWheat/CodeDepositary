#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
vector<int> arr;
vector<int> prefixSum;
vector<int> surfixSUm;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int k = (m / n) - 1;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int left = max(0ll, arr[i] - k);
        result += (left + arr[i]) * (arr[i] - left + 1) / 2;
        arr[i] = max(left - 1, 0ll);
    }

    int extra = m % n;
    if (extra != 0)
    {
        prefixSum.resize((n * 2) + 1);
        for (int i = 1; i <= 2 * n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + arr[(i-1) % n];
        }
        int maxi = 0;
        for (int i = extra; i <= n * 2; i++)
        {
            maxi = max(maxi, prefixSum[i] - prefixSum[i - extra]);
        }
        result += maxi;
    }

    cout << result << '\n';

    return 0;
}
