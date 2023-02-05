#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<string> inputOrder;
map<string, vector<string>> ma;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        inputOrder.push_back(input);
        ma[input].resize(k + 1, "0");
    }

    for (int i = 0; i < m; i++)
    {
        int a;
        string input, b;
        cin >> input;
        if (input == "view")
        {
            for (auto j : inputOrder)
            {
                cout << j << ' ';
                bool flag = true;
                for (auto o : ma[j])
                {
                    if (flag)
                    {
                        flag = false;
                        continue;
                    }
                    for (auto l : o)
                    {
                        cout << l;
                    }
                    cout << ' ';
                }
                cout << '\n';
            }
            continue;
        }

        cin >> a >> b;
        if (b == "AC") 
        {
            ma[input][a] = '+' + to_string(abs(stoi(ma[input][a])));
            continue;
        }
        if (ma[input][a][0] == '+')
        {
            continue;
        }
        if (b == "WA" || b == "TLE" || b == "MLE")
        {
            ma[input][a] = to_string((stoi(ma[input][a]) - 1));
            continue;
        }
    }
}

