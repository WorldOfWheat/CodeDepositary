#include <bits/stdc++.h>

using namespace std;

int n;
string str;
stack<string> st;
queue<string> qu;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        string input;
        cin >> input;
        if (input == "]")
        {
            while (st.top() != "[")
            {
                qu.push(st.top());
                st.pop();
            }
            st.pop();
            while (qu.size())
            {
                st.push(qu.front());
                qu.pop();
            }
            continue;
        }
        st.push(input);
    }
    vector<string> result;
    while (st.size())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    for (auto i : result)
    {
        cout << i << ' ';
    }
}
