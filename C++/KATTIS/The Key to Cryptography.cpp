#include <iostream>

using namespace std;

string str, str2;

int main() {

    cin >> str >> str2;
	
	string res = "";
	string block = str2;

	for (int i = 0; i < str.length(); i++) {
		char k = (str[i] + 26 - block[i]) % 26 + 'A';
		block += k;
		res += k;
	}

	cout << res << "\n";

    return 0;

}