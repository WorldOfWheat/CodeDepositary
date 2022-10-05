#include <bits/stdc++.h>
#define int long long
#define VP vector<pii>
#define V vector<int>
#define VV vector<V>
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

int n, m, o, p;
V ve;
V dis;

void bfs() {

	queue<int> qu;
	qu.push(0);
	dis[0] = 0;

	while (qu.size()) {
		int top = qu.front();
		qu.pop();

		int now = top + p;
		while (0 <= now && now < n) {
			if (dis[now] != -1) {
				break;
			}
			dis[now] = dis[top] + 1;

			if (now == ve[now]) {
				qu.push(now);
				break;
			
			}

			now = ve[now];
		}

		now = top - o;
		while (0 <= now && now < n) {
			if (dis[now] != -1) {
				break;
			}
			dis[now] = dis[top] + 1;

			if (now == ve[now]) {
				qu.push(now);
				break;
			}

			now = ve[now];
		}
	}

	cout << (dis[m]) << ln;
}

void solve() {

	cin >> n >> m >> o >> p;

	ve.resize(n);
	dis.resize(n, -1);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	bfs();

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}