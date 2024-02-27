#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define VV vector<vector<int>>
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

string str, str2;
VV dp;
VV status;

void solve() {

	dp.clear();
	status.clear();

	cout << (str) << sp << (str2) << " = ";

	int len = str.length();
	int len2 = str2.length();

	dp.resize(len+1, V(len2+1));
	status.resize(len+1, V(len2+1));
	
	rep2 (i, 1, len) {
		rep2 (j, 1, len2) {
			char top = str[i-1];
			char top2 = str2[j-1];

			if (top == top2) {
				dp[i][j] = dp[i-1][j-1] + 1;
				status[i][j] = 3;

				continue;
			}

			if (dp[i-1][j] > dp[i][j-1]) {
				dp[i][j] = dp[i-1][j];

				status[i][j] = 1;
			}	
			else {
				dp[i][j] = dp[i][j-1];

				status[i][j] = 2;
			}
		}
	}

	stringstream ss;

	int nowX = len, nowY = len2;
	while (nowX > 0 && nowY > 0) {
		switch (status[nowX][nowY]) {
			case 1:
				nowX--;
				break;

			case 2:
				nowY--;
				break;

			case 3:
				ss << str[nowX-1];
				nowX--;
				nowY--;
				break;
		}
	}

	str = ss.str();

	reverse(str.begin(), str.end());

	if (str.length() == 0) {
		cout << 0 << ln;
		
		return;
	}

	for (auto i : str) {
		cout << i;
	}
	cout << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> str >> str2) solve();

	return 0;

}