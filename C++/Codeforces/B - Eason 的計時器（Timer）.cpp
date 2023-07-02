#include <bits/stdc++.h>
#define int long long
#define VS vector<string>
#define V vector<int>
#define VV vector<V>
#define VP vector<PII>
#define VVP vector<VP>
#define PII pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define nl '\n';
#define INF (int) 1e18
#define MOD (int) 1e9 + 7

using namespace std;

int n, m;
V arr;
V prefixSum;
list<int> li;
list<int> li2;

void monotonicAdd(list<int> &_list, bool incressment, int expired, int value)
{
    while (_list.size() && _list.front() < expired)
    {
        _list.pop_front();
    }
    while (_list.size() && ((incressment && arr[_list.back()] > arr[value]) || (!incressment && arr[_list.back()] < arr[value])) )
    {
        _list.pop_back();
    }
    _list.push_back(value);
}

void query(int x)
{
    li.clear();
    li2.clear();
    rep (i, 0, x)
    {
        monotonicAdd(li, true, 0, i);
        monotonicAdd(li2, false, 0, i);
    }
    // for (auto i : li)
    // {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (auto i : li2)
    // {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // cout << "#" << prefixSum[x] << ' ' << arr[li.front()] << ' ' << arr[li2.front()] << ' ' << (x - 2) << endl;
    cout << (prefixSum[x] - arr[li.front()] - arr[li2.front()]) / (x - 2) << ' ';
    // cout << endl;

    int expired_counter = 1;
    rep (i, x, n)
    {
        monotonicAdd(li, true, expired_counter, i);
        monotonicAdd(li2, false, expired_counter, i);
        // for (auto i : li)
        // {
        //     cout << i << ' ';
        // }
        // cout << endl;
        // for (auto i : li2)
        // {
        //     cout << i << ' ';
        // }
        // cout << endl << "---" << endl;
        // cout << "#" << i << ": " << prefixSum[i + 1] << ' ' << prefixSum[expired_counter] << ' ' << arr[li.front()] << ' ' << arr[li2.front()] << ' ';
        cout << (prefixSum[i + 1] - prefixSum[expired_counter] - arr[li.front()] - arr[li2.front()]) / (x - 2) << ' ';
        expired_counter++;
        // cout << endl << "---" << endl;
    }
    cout << '\n';
}

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    prefixSum.resize(n + 1);
    for (auto &i : arr)
    {
        cin >> i;
    }

    rep2 (i, 1, n)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    rep(i, 0, m)
    {
        int k;
        cin >> k;
        query(k);
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
