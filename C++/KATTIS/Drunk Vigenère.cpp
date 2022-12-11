#include <bits/stdc++.h>

using namespace std;



int main() {

    string str;
    string str2;

    cin >> str >> str2;

    string ans = "";
    int len = str.length();
    for (int i = 0; i < len; i++) {
        str[i] -= 'A';
        str2[i] -= 'A';
        
        if (i % 2 == 0) {
            int k = str[i] - str2[i];
            if (k < 0) {
                k += 26;
            } 
            ans += k % 26;
        }
        else {
            ans += (str[i] + str2[i]) % 26;
        }
    }

    for (int i = 0; i < len; i++) {
        //cout << (int)  (ans[i]) << ' ';
        cout << (char) (ans[i] + 'A');
    }

    cout << '\n';

    return 0;

}
