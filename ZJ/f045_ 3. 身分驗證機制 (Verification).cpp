#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

string str;
vector<int> ve;

void solve() {
        
    cin >> str;
    for (auto a : str) {
        ve.push_back(a - '0');
    }
    sort(ve.begin(), ve.end());
    int sum = ve.back() * ve.back();
    ve.pop_back();
    sum += ve.back() * ve.back();

    if ( sum == atoi(str.substr(6).c_str() ) ) {
        cout << "Good Morning!" << ln;
    }
    else {
        cout << "SPY!" << ln;
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
