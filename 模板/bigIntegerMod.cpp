int bigIntegerMod(string x, int mod) {
    int res = 0;
    for (auto i : x) {
        res *= 10;
        res %= mod;
        res += i - '0';
        res %= mod;
    }
    return res;
}