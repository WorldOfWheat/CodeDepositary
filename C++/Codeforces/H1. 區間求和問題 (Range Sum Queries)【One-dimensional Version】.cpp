#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<long long> arr;
vector<long long> prefixSum;

void solve() 
{
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        long long input;
        cin >> input;
        arr.push_back(input);
    }

    prefixSum.resize(n + 1);

    for (int i = 1; i <= n; i++) 
    {
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    }

    cin >> m;

    for (int i = 0; i < m; i++) 
    {
        int input1, input2;
        cin >> input1 >> input2;

        cout << (prefixSum[input2] - prefixSum[input1 - 1]) << '\n';
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}
