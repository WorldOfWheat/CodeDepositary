int _jumping_search(int x) {
    if (ve[0] > x) {
        return 0;
    }
    int res = 0;
    for (int i = ve.size() >> 1; i > 0; i >>= 1) {
        while (res + i < ve.size() && ve[res + i] < x) {
            res += i;
        }
    }
    return res+1;
}