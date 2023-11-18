int gcd(int x, int y) {
	if (y > x) {
		return _gcd(y, x);
	}
	if (y == 0) {
		return x;
	}
	return _gcd(y, x % y);
}