void discrete(vector<int> &x) {
    vector<int> temp = x;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (auto &i : x) {
        i = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
    }
}