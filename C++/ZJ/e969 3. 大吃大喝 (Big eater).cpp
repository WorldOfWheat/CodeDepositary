#include <bits/stdc++.h>

using namespace std;

int input1, input2, input3;
vector<int> foods = {32, 55};
vector<string> sentences = {
    ": Wayne eats an Apple pie, ",
    ": Wayne drinks a Corn soup, " 
    };

void solve() 
{

    cin >> input1 >> input2 >> input3;

    if (input1 < foods[input3]) 
    {
        cout << "Wayne can't eat and drink." << '\n';
        return;
    }

    int timeNow = 0;
    while (input1 >= foods[input3]) 
    {
        input1 -= foods[input3];
        cout << timeNow << sentences[input3];
        if (input1 == 0)
        {
            cout << "and now he doesn't have money.";
        }
        else if (input1 == 1)
        {
            cout << "and now he has 1 dollar.";
        }
        else
        {
            cout << "and now he has " << input1 << " dollars.";
        }
        cout << '\n';
        
        input3 = 1 - input3;
        timeNow += input2;
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}
