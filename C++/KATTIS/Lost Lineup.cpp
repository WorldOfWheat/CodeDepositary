#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n+1];
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        arr[a+2] = i;
    }

    cout << 1 << " ";
    for (int i = 2; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}