int exgcd(int a, int b, int &x, int &y) {
    //b % a 的模逆元為 y
    if (b > a) {
        return exgcd(b, a, x, y);
    }

    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    int res = exgcd(b, a % b, x, y); 
    int temp = x; 
    x = y;
    y = temp - (a / b) * y;

    return res;
}
