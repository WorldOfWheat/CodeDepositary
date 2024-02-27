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
#define MN (int) 1e18

using namespace std;

V ve;

int dfs(int l, int r) {

	if (l >= r) {
		return 0;
	}

	int mid = (l + r) >> 1;
	int res = 0;

	res += dfs(l, mid);
	res += dfs(mid+1, r);

	stable_sort(ve.begin() + mid + 1, ve.begin() + r + 1);

	rep2 (i, l, mid) {
		auto it = lower_bound(ve.begin() + mid + 1, ve.begin() + r + 1, ve[i]);
		res += distance((ve.begin() + mid + 1), it);
	}

	return res;

}

void solve() {

	int n;
	cin >> n;

	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}

	cout << dfs(0, ve.size() - 1) << ln;

}

signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}

///////////////////////////////////////////////////////////////////////////////////////////////

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
#define MN (int) 1e18

using namespace std;

V ve;

int dfs(int l, int r) {

	if (l >= r) {
		return 0;
	}

	int mid = (l + r) / 2;

	int res = 0;
	res += dfs(l, mid);
	res += dfs(mid + 1, r);

	int ptrr = mid + 1;
	V temp;

	rep2 (ptrl, l, mid) {
		while (ptrr <= r && ve[ptrr] < ve[ptrl]) {
			temp.push_back(ve[ptrr]);
			ptrr++;
		}
		
		temp.push_back(ve[ptrl]);

		res += ptrr - (mid + 1);
	}

	rep (i, l, ptrr) {
		ve[i] = temp[i-l];
	}

	return res;

}

void solve() {

	int n;
	cin>> n;

	ve.resize(n);
	rep (i, 0, n) {
		cin >> ve[i];
	}

	cout << (dfs(0, ve.size()-1)) << ln;

}

signed main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}

///////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
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

int n;
V ve;
V bit;

int getLowbit(int x) {
    return x & -x;
}

void update(int pos, int value) {

    for (int i = pos; i <= n; i += getLowbit(i)) {
        bit[i] += value;
    }

}

int query(int pos) {

    int res = 0;
    for (int i = pos; i >= 1; i -= getLowbit(i)) {
        res += bit[i];
    }

    return res;

}

void solve() {

    cin >> n;

    ve.resize(n + 1);
    bit.resize(n + 1);

    rep (i, 0, n) {
        cin >> ve[i];
    }

    V temp(ve);
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    rep (i, 0, n) {
        ve[i] = lower_bound(temp.begin(), temp.end(), ve[i]) - temp.begin();
    }

    int ans = 0;
    rep (i, 0, n) {
        ans += (i - query(ve[i]));
        update(ve[i], 1);
    }

    cout << ans << ln;
}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
