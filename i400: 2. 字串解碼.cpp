#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    string str;
    cin >> str;
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        deque<char> dq;
        int k = str.length()-1;
        string a = *it;
        for (auto it2 = a.rbegin(); it2 != a.rend(); it2++) {
            int temp = *it2;
            if (temp-48 == 1)
                dq.push_back(str[k]);
            else
                dq.push_front(str[k]);
            k--;
        }
        stringstream ss;
        while (!dq.empty()) {
            ss << dq.front();
            dq.pop_front();
        }
        str = ss.str();
        int sum = 0;
        for (auto b :a) if (b == '1') sum++;
        if (sum % 2 == 1) {
            if (str.length() % 2 == 1)
                str = str.substr(str.length()/2+1, str.length()) + str.substr(str.length()/2, 1) +  str.substr(0, str.length()/2);
            else
                str = str.substr(str.length()/2, str.length()) + str.substr(0, str.length()/2);
        }
    }
    cout << str << endl;
    return 0;
}
