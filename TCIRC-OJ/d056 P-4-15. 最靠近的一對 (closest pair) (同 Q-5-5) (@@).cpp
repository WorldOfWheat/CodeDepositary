#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

VP ve;
multimap<int, int> mma;

void solve() {
	
	int n;
	cin >> n;

	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i].F >> ve[i].S;
	}

	sort(ve.begin(), ve.end());

	int ans = INF;
	rep (i, 0, n) {
		pii top = ve[i];

		auto it = mma.lower_bound(top.S - ans);
		while (it != mma.end()) {
			if (abs((it->S) - top.F) >= ans) {
				it = mma.erase(it);
				continue;
			}
			
			ans = min(ans, abs(top.F - (it->S)) + abs(top.S - (it->F)));
			it = next(it);
		}

		mma.insert({top.S, top.F});

	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

VP ve;

int dfs(int l, int r) {

	if (l >= r) {
		return INF;
	}

	int mid = (l + r) / 2;
	int midPos = ve[mid].F;
	int res = min(dfs(l, mid), dfs(mid+1, r));
	
	VP temp(r - l + 1);
	auto it = ve.begin();
	merge(it + l, it + mid + 1, it + mid + 1, it + r + 1, temp.begin(), [](pii x, pii y) {return x.S < y.S;});

	rep2 (i, l, r) {
		ve[i] = temp[i-l];
	}

	temp.clear();

	rep2 (i, l, r) {
		if (abs(ve[i].F - midPos) <= res) {
			temp.push_back(ve[i]);
		}
	}

	rep (i, 0, temp.size()) {
		rep (j, i+1, temp.size()) {
			res = min(res, abs(temp[i].F - temp[j].F) + abs(temp[i].S - temp[j].S));
			if (abs(temp[i].S - temp[j].S) > res) {
				break;
			}
		}
	}

	return res;

}

void solve() {
	
	int n;
	cin >> n;
	
	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i].F >> ve[i].S;
	}

	sort(ve.begin(), ve.end());

	cout << (dfs(0, ve.size()-1)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
