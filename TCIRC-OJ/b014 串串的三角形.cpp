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

vector<double> ve(3);

void solve() {

	rep (i, 0, 3) {
		cin >> ve[i];
	}

	sort(ve.begin(), ve.end());

	if (ve[0] + ve[1] <= ve[2] || ve[1] + ve[2] <= ve[0]) {
		cout << "NULL" << ln;
		return;
	}

	double k = sqrt((ve[0] * ve[0]) + (ve[1] * ve[1])) - ve[2];

	if (k == 0) {
		cout << "Right Triangle" << ln;
		return;
	}

	if (k < 0) {
		cout << "Obtuse Triangle" << ln;
		return;
	}

	cout << "Acute Triangle" << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}