void merge_sort(vector<int> &x, int l, int r) {

	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	merge_sort(x, l, mid);
	merge_sort(x, mid+1, r);

	vector<int> res(r - l + 1);
	merge(x.begin() + l, x.begin() + mid + 1, x.begin() + mid + 1, x.begin() + r + 1, res.begin());
	
	for (int i = l; i <= r; i++) {
		x[i] = res[i-l];
	}

}