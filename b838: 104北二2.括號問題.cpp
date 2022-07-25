#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        stack<char> brackets;
        int left = 0, right = 0, sum = 0;
        for (auto a : input) {
            if (a == '(') {
                left++;
                brackets.push(a);
            } else {
                right++;
                if (!brackets.empty() && brackets.top() == '(') {
                    sum++;
                    brackets.pop();
                }
            }
        }
        cout << ( (brackets.empty() && right == left) ? sum : 0) << endl;
        if (brackets.empty() && right == left) {

        }
    }

    return 0;
}
