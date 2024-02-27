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



void solve() {

	char ch;
	while (ch = getchar()) {
		if (ch == EOF) {
			break;
		}
		switch (ch) {
			case 'A':
				putchar('U');
				break;
			
			case 'T':
				putchar('A');
				break;
			
			case 'C':
				putchar('G');
				break;

			case 'G':
				putchar('C');
				break;

			default:
				putchar(ch);
				break;
		}
	}

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}