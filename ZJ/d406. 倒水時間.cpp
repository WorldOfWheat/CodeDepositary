#include <bits/stdc++.h>
#define int long long
#define pa pair<int, int>
#define tp tuple<int, int, int>

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int ud[4] = {1, -1, 0, 0};
    const int lr[4] = {0, 0, -1, 1};

    int t;
    int times = 1;
    for (int i = 1; cin >> t;) {
        cout << "Case " << times << ":\n";
        times++;
        int n, m;
        cin >> n >> m;
        int arr[n+1][m+1];
        memset(&arr, 0, sizeof(arr));
        int start;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cin >> arr[j][k];
                if (arr[j][k] == 1 && j == 1) {
                    start = k;
                }
            }
        }
        queue<tp> q;
        q.push(make_tuple(1, start, 1));
        while (!q.empty()) {
            tp f = q.front();
            int a = get<0>(f);
            int b = get<1>(f);
            int c = get<2>(f);
            arr[a][b] = c;
            for (int j = 0; j < 4; j++) {
                int d = a+ud[j];
                int e = b+lr[j];
                if (ud[j] != 0) {
                    if (arr[d][e] == 1) {
                        if ( !(t==2 && ud[j] == -1) )
                            q.push(make_tuple(d, e, c+1));
                    }
                }
                if (lr[j] != 0) {
                    if (arr[d][e] == 1) {
                        q.push(make_tuple(d, e, c+1));
                    }
                }
            }
            q.pop();
        }
        arr[1][start] = 1;
        for (int j = 1;  j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (j == 1 && k == start)
                    cout << 1 << " ";
                else if (arr[j][k] == 1)
                    cout << 0 << " ";
                else
                    cout << arr[j][k] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}
