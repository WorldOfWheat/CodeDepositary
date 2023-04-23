#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> numbers;

void solve() 
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        numbers.emplace_back(i);
    }

    string result = "";
    do
    {
        for (auto i : numbers) 
        {
            result += to_string(i) + ' ';
        }
        result += '\n';
    } while (next_permutation(numbers.begin(), numbers.end()));

    cout << result;
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
