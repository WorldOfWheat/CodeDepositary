class int128_io {
    __int128 read() {
        char in;
        bool flag = false;
        __int128 res = 0;
        while (in = getchar(), in >= '0' && in <= '9') {
            res *= 10;
            res += in - '0';
        }

        return res;
    }
    void print(__int128 x) {
        if (x > 9) {
            print(x / 10);
        }
        putchar(x % 10 + '0');
    }
};