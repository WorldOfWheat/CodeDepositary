int qpow(int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
}

///////////////////////////////////////////////////////////////

int qpow(int x, int y, int mod) {
    if (y == 0) {
        return 1;
    }
    if (y == 1) {
        return x;
    }
    if (y & 1) {
        return x * qpow(x, y-1, mod) % mod;
    }
    int res = qpow(x, y >> 1, mod);
    return res * res % mod;
}
