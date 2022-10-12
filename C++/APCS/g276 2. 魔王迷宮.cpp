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

struct player{
	int nowX, nowY;
	int moveX, moveY;
};

int n, m, k;
vector<player> players;
VV bombs;
bitset<500+5> vis;

void solve() {

	cin >> n >> m >> k;	

	bombs.resize(n, V(m));
	players.resize(k);

	rep (i, 0, k) {
		player &top = players[i];
		cin >> top.nowX >> top.nowY >> top.moveX >> top.moveY;
	}

	while (vis.count() != players.size()) {
		rep (i, 0, k) {
			if (vis[i]) {
				continue;
			}

			player top = players[i];
			int x = top.nowX;
			int y = top.nowY;

			bombs[x][y]++;
		}
		VP temp;
		rep (i, 0, k) {
			if (vis[i]) {
				continue;
			}

			player &top = players[i];
			top.nowX += top.moveX;
			top.nowY += top.moveY;
			int x = top.nowX;
			int y = top.nowY;

			if (x < 0 || y < 0) {
				vis[i] = 1;
				continue;
			}
			if (x >= n || y >= m) {
				vis[i] = 1;
				continue;
			}
			if (bombs[x][y]) {
				vis[i] = 1;
				temp.push_back({x, y});
			}
		}
		for (auto i : temp) {
			bombs[i.F][i.S] = 0;
		}
	}

	int ans = 0;
	rep (i, 0, n) {
		rep (j, 0, m) {
			ans += (bool) bombs[i][j];
		}
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}