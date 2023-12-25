#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class miller_rabin 
{
private:
    long long* test_numbers;

    long long modulo_multiply(long long x, long long y, long long mod) 
    {
        long long result = 0;
        while (y > 0) 
        {
            if (y & 1ll) result = (result + x) % mod;
            x <<= 1ll;
            x %= mod;
            y >>= 1ll;
        }
        return result;
    }

    long long fast_pow(long long x, long long y, long long mod) 
    {
        long long result = 1ll;
        while (y > 0) 
        {
            if (y & 1) result = modulo_multiply(result, x, mod);
            x = modulo_multiply(x, x, mod);
            y >>= 1ll;
        }
        return result;
    }

public:
    miller_rabin()
    {
        test_numbers = (long long*) malloc(sizeof(long long) * 7);
        test_numbers[0] = 2;
        test_numbers[1] = 325;
        test_numbers[2] = 9375;
        test_numbers[3] = 28178;
        test_numbers[4] = 450775;
        test_numbers[5] = 9780504;
        test_numbers[6] = 1795265022;
    }

    char is_prime(long long number) 
    {
        if ((number == 1) || ((number & 1) == 0)) return number == 2;

        long long n = number - 1, m = n;
				char k = 0;
        while ((m & 1) == 0) 
        {
            k++;
            m >>= 1ll;
        }
        
        for (char i = 0; i < 7; i++)
        {
            long long test_number = test_numbers[i];
            if (test_number >= number) break;

            long long b = fast_pow(test_number, m, number);
            if (b == 1 || b == n) continue;

            char flag = 1;
            for (long long j = 0; j < k - 1; j++)
            {
                b = modulo_multiply(b, b, number);
                
                if (b == n)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag) return 0;
        }
        return 1;
    }
};;

ll n;

void solve()
{
    miller_rabin mr;

    while (cin >> n)
    {
        if (mr.is_prime(n)) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}
