bool isPrime(int x) {
    if (x <= 1 || x % 2 == 0 || x % 3 == 0) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    int sw = 2;
    for (int i = 5; i <= (int) sqrt(x); i += sw, sw = 6 - sw) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}