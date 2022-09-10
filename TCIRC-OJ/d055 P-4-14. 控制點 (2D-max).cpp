#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
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
#define MAXN (int) 1e18

using namespace std;

VP ve;
set<int> se;
stack<int> st;

void solve() {
	
	int n;
	cin >> n;
	ve.resize(n);

	rep (i, 0, n) {
		cin >> ve[i].F;
	}
	rep (i, 0, n) {
		cin >> ve[i].S;
		se.insert(ve[i].S);
	}

	sort(ve.begin(), ve.end());
	
	rep (i, 0, n) {
		pii top = ve[i];
		while (st.size() && st.top() <= top.S) {
			st.pop();
		}
		st.push(top.S);
	}

	cout << (st.size()) << ln;

}

signed main() {
    
	ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
