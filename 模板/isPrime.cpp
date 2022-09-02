bool isPrime(int x) {
    srand(time(0));
    if (x <= 2) {
        return x == 2;
    }
    for (int i = 0; i < 10; i++) {
        int r = ((rand() % ( (x - 1) - 2 + 1)) + 2);
        if (qpow(r, x - 1, x) != 1) {
            return false;
        }
    }
    return true;
}