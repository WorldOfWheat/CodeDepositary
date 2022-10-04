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

const V dirX = {1, -1, 0, 0};
const V dirY = {0, 0, 1, -1};

int n, m;
VV graph;
VV vis;

int bfs(int x, int y) {

	queue<pii> qu;
	qu.push({x, y});
	vis[x][y] = true;
	
	int res = graph[x][y];
	while (qu.size()) {
		pii top = qu.front();
		qu.pop();

		int mini = INF;
		int nextX, nextY;
		bool flag = false;
		rep (i, 0, 4) {
			int dx = (top.F) + dirX[i];
			int dy = (top.S) + dirY[i];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || vis[dx][dy]) {
				continue;
			}

			if (graph[dx][dy] < mini) {
				flag = true;
				mini = graph[dx][dy];
				nextX = dx;
				nextY = dy;
			}

		}
		
		if (flag) {
			vis[nextX][nextY] = true;
			res += graph[nextX][nextY];
			qu.push({nextX, nextY});
		}
	}

	return res;

}

void solve() {

	cin >> n >> m;

	graph.resize(n, V(m));
	vis.resize(n, V(m));

	int nowX, nowY;
	int mini = INF;
	rep (i, 0, n) {
		rep (j, 0, m) {
			cin >> graph[i][j];
			if (graph[i][j] < mini) {
				nowX = i;
				nowY = j;
				mini = graph[i][j];
			}
		}
	}

	cout << (bfs(nowX, nowY)) << ln;	

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}