#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] - n < 'A') {
            cout << char(str[i] - n + 26);
            continue;
        }
        cout << (char(str[i] - n));
    }
    cout << "\n";

    return 0;

}