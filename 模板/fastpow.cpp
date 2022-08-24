int fastpow(int x, int y, int mod) {
    
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