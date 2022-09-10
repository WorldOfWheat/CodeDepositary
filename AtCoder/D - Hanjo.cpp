#include <bits/stdc++.h>
#define int long long

using namespace std;
__attribute__((optimize("-O3")))

int h, k, A, B;
int arr[16+1][16+1];
int cnt;
void dfs(int z, int w) {
    //cout << z << " " << w << endl;
    if (z == 0 && w == 0) {
        bool flag = true;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < k; j++) {
                if (arr[i][j] == 0) flag = false;
            }
        }
        if (flag) cnt++;
        return;
    }
    int x = 0, y = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < k; j++) {
            //cout << arr[i][j] << endl;
            if (arr[i][j] == 0) {
                x = i;
                y = j;
                goto stop1;
            }
        }
    }
    stop1:
    //cout << x << " " << y << endl;
    if (z > 0) {

        if (arr[x][y] == 0 && arr[x][y+1] == 0 && y+1 < k) {
            arr[x][y]++;
            arr[x][y+1]++;

            dfs(z-1, w);

            arr[x][y]--;
            arr[x][y+1]--;
        }



        if (arr[x][y] == 0 && arr[x+1][y] == 0 && x+1 < h) {
            arr[x][y]++;
            arr[x+1][y]++;

            dfs(z-1, w);

            arr[x][y]--;
            arr[x+1][y]--;
        }

    }

    if (w > 0) {

        if (arr[x][y] == 0) {
            arr[x][y]++;

            dfs(z, w-1);

            arr[x][y]--;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> k >> A >> B;
    dfs(A, B);
    cout << cnt << "\n";

    return 0;
}
