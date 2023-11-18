#include <iostream>

using namespace std;
 
int main() {

    string str;

    cin >> str;
    
    cout << (str.length()) << "\n";

    return 0;

}

/////////////////////////////////////////////////////////////////////////

#include <iostream>
#define ln "\n"

using namespace std;
 
int main() {

    int n;
    cin >> n;

    int ans = 0;
    while (n > 0) {
        n /= 10;
        ans++;
    }

    cout << ans << ln;

    return 0;

}

