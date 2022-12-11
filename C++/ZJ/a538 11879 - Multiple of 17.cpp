#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while (cin >> str && str != "0") {
        int sum = 0;

        int len = str.length();
        for (int i = 0; i < len; i++) {
            sum *= 10;
            sum += str[i] - '0';
            sum %= 17;
        }

        cout << (sum == 0)  << '\n';
    }

    return 0;

}
