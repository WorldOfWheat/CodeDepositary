#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
list<string> li;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) 
    {
        int a, b;
        char c;
        cin >> a;
        if (a != 5)
        {
            cin >> b;
            if (a != 3 && a != 4)
            {
                cin >> c;
            }
        }
        switch (a)
        {
            case 1:
            {
                string &temp = li.back();
                int length = temp.length();
                if (li.size() > 0 && temp[temp.length() - 1] == c)
                {
                    if (temp[length - 1] == c)
                    {
                        temp = to_string(stoll(temp.substr(0, length - 1)) + b) + c;
                    }
                }
                else
                {
                    li.push_back(to_string(b) + c);
                }
                break;
            }
            case 2:
            {
                string &temp = li.front();
                int length = temp.length();
                if (li.size() > 0 && temp[temp.length() - 1] == c)
                {
                    if (temp[length - 1] == c)
                    {
                        temp = to_string(stoll(temp.substr(0, length - 1)) + b) + c;
                    }
                }
                else
                {
                    li.push_front(to_string(b) + c);
                }
                break;
            }
            case 3:
            {
                while (b > 0)
                {
                    string &temp = li.back();
                    int length = temp.length();
                    int number = stoll(temp.substr(0, length - 1));
                    if (number - b > 0) 
                    {
                        temp = to_string(number - b) + temp.back();
                        b = 0;
                    }
                    else
                    {
                        b -= number;
                        li.pop_back();
                    }
                }
                break;
            }
            case 4:
                while (b > 0)
                {
                    string &temp = li.front();
                    int length = temp.length();
                    int number = stoll(temp.substr(0, length - 1));
                    if (number - b > 0) 
                    {
                        temp = to_string(number - b) + temp.back();
                        b = 0;
                    }
                    else
                    {
                        b -= number;
                        li.pop_front();
                    }
                }
                break;
            case 5:
            {
                for (auto it = li.begin(); it != li.end(); it++)
                {
                    cout << (*it);
                }
                cout << '\n';
                break;
            }
        }
    }
}

