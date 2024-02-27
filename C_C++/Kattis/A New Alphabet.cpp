#include <iostream>

using namespace std;

int main() {

    string table[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", 
                    "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", 
                    "\\/", "\\/\\/", "}{", "`/", "2"};

    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            cout << (table[str[i] - 'A']); 
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            cout << table[str[i] - 'a'];
        }
        else {
            cout << str[i];
        }
    }

    return 0;

}