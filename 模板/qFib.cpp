int qFib(int x) {
    vv mul = {
        {1, 1},
        {1, 0}
    };
    vv res = {
        {1, 1},
        {1, 0}
    };
    while (x > 0) {
        if (x & 1) {
            res = matrixMul(res, mul);
        }
        mul = matrixMul(mul, mul);
        x >>= 1;
    }
    return res[0][0];
}