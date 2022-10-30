#include <iostream>

using namespace std;

int main() {

    string str;
    cin >> str;

    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (flag) {
            cout << str[i];
            flag = false;
        }
        if (str[i] == '-') {
            flag = true;
        }
    }

    cout << "\n";

    return 0;

}