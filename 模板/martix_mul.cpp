vector<vector<int>> martix_mul(vv x, vv y) {

	int _size = x.size();
    vector<vector<int>> res(_size, vector<int>(_size));
	
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
			
            int sum = 0;
			
			for (int o = 0; o < _size; o++) {
                sum += x[i][o] * y[o][j];
            }
			
            res[i][j] = sum;
			
        }
    }
	
    return res;

}