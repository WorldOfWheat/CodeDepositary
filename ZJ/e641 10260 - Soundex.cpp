#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

string str;
map<char, int> mp = {
{'B', 1},
{'F', 1},
{'P', 1},
{'V', 1},

{'C', 2},
{'G', 2},
{'J', 2},
{'K', 2},
{'Q', 2},
{'S', 2},
{'X', 2},
{'Z', 2},

{'D', 3},
{'T', 3},

{'L', 4},

{'M', 5},
{'N', 5},

{'R', 6}
};

void solve() {
    stringstream ss;
    int last = -1;
    for (auto i : str) {
        int a = mp[i];
        if (a && a != last) {
            ss << a;
        }
        last=  a;
    }
    cout << (ss.str()) << ln;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str) solve();

    return 0;
}
