#include <iostream>

using namespace std;

int main() {

    int arr[3] = {1, 0, 0};

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'A') {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        else if (str[i] == 'B') {
            int temp = arr[1];
            arr[1] = arr[2];
            arr[2] = temp;
        }
        else {
            int temp = arr[0];
            arr[0] = arr[2];
            arr[2] = temp;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (arr[i]) {
            cout << (i+1);
        }
    }

    return 0;

}