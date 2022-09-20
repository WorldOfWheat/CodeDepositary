void merge_sort(vector<int> &x, int l, int r) {
	
	if (l >= r) {
		return;
	}

	int mid = (l + r) / 2;

	merge_sort(x, l, mid);
	merge_sort(x, mid+1, r);

	auto it = x.begin();
	vector<int> res(r - l + 1);
	merge(it + l, it + mid + 1, it + mid + 1, it + r + 1, res.begin());

	for (int i = l; i <= r; i++) {
		x[i] = res[i-l];
	}

}