#include <iostream>

using namespace std;

int arr[26+1];

int main() {

    int t;
    string str;
    getline(cin, str);
    t = stoi(str);
    while (t--) {

        for (int i = 0; i < 26; i++) {
            arr[i] = 0;
        }

        string str;
        getline(cin, str);

        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                arr[str[i] - 'A']++;
                continue;
            }
            else if(str[i] >= 'a' && str[i] <='z') {
                arr[str[i] - 'a']++;
            }
        }
        
        int maxi = (int) -1e9;
        for (int i = 0; i < 26; i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] >= maxi) {
                cout << char('a' + i);
            }
        }
        cout << "\n";
    }

    return 0;

}