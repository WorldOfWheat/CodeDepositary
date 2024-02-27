#include <bits/stdc++.h>
#define int long long
#define V vector<int>
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

void solve() {
	string str;
	cin >> str;
	string str2;
	cin >> str2;
	cout << str2 << sp;
	while (cin >> str2) {
		cout << str << sp << str2 << sp;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
