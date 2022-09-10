#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<int> city[800+1] ;
bool hasWalk[800+1];
void dfs(int start) {
    hasWalk[start] = true;
    for (auto &a : city[start]) {
        if (!hasWalk[a]) dfs(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        memset(&city, 0, sizeof(city));
        memset(&hasWalk, false, sizeof(hasWalk));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            city[a].push_back(b);
        }

        for (int i = 0; i <= n; i++) hasWalk[i] = false;
        int in_a, in_b;
        cin >> in_a >> in_b;
        dfs(in_a);
        cout << (hasWalk[in_b] ? "Yes!!!" : "No!!!") << endl;
    }
    return 0;
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int n, m;
    while (cin >> n >> m) {
        vector<int> city[n+1];
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            city[a].push_back(b);
        }
        bool hasWalk[n+1];
        for (int i = 0; i <= n; i++) hasWalk[i] = false;
        stack<int> dfs;
        int in_a, in_b;
        cin >> in_a >> in_b;
        if (in_a == in_b) {
            cout << "Yes!!!" << endl;
            continue;
        }
        dfs.push(in_a);
        hasWalk[in_a] = true;
        int now = in_a;
        while (!dfs.empty()) {
            hasWalk[now] = true;
            int top = dfs.top();
            dfs.pop();
            for (auto &a : city[top]) {
                if (!hasWalk[a]) {
                    dfs.push(a);
                    now = a;
                }
            }
        }
        cout << (hasWalk[in_b] ? "Yes!!!" : "No!!!") << endl;
    }
    return 0;
}
