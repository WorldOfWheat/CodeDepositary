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


int n;
set<pair<int, string>> se;
map<int, int> ma;

void solve()
{
    cin >> n;
    se.insert({1, "Init"});
    rep (i, 0, n)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "fork")
        {
            int k;
            cin >> k;
            auto lower = se.lower_bound({k, ""});
            int new_index = se.rbegin()->F + 1;
            ma[new_index] = lower->F;
            se.insert({new_index, lower->S});
            cout << new_index << ' ' << (se.rbegin()->S) << '\n';
        }
        else if (cmd == "exec")
        {
            int k;
            string new_data;
            cin >> k >> new_data;
            auto lower = se.lower_bound({k, ""});
            cout << (lower->S) << '\n';
            se.erase(lower);
            se.insert({k, new_data});
        }
        else
        {
            int k;
            cin >> k;
            auto lower = se.lower_bound({k, ""});
            int parent_index = ma[lower->F];
            auto lower_parent = se.lower_bound({parent_index, ""});
            if (lower_parent == se.end() || lower_parent->F != parent_index)
            {
                cout << 1 << '\n';
                continue;
            }

            cout << (parent_index) << '\n';
            se.erase(lower);
        }
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
