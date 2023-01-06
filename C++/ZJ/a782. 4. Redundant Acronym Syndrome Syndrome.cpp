#include <bits/stdc++.h>
#define int long long
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
#define ln '\n'

using namespace std;

vector<string> ve;

void solve() {
    string in;
    while (true) {
        ve.clear();
        in = "";

        getline(cin, in);
        if (in == "END") {
            break;
        }

        string str = "";
        for (auto i : in) {
            if (i == ' ') {
                ve.push_back(str);
                str = "";
                continue;
            }
            str += i;
        }
        ve.push_back(str);
        
        for (auto i : ve) {
            cout << ((char) toupper(i[0]));
        }
        cout << ' ' << (ve.back()) << ln;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}

