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

vector<int> ve;
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
	int n, m;
	cin >> n >> m;
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}
	int ans = 0;
	rep (i, 0, n) {
		int top = ve[i];
		if (pq.size() < m) {
			pq.push(top);
		}
		else {
			pq.push(pq.top() + top);
			ans = max(ans, pq.top() + top);
			pq.pop();
		}
	}
	cout << (ans) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
