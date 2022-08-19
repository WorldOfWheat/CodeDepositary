void discrete(vector<int> &x) {
    vector<int> order;
    order.assign(x.begin(), x.end());

    sort(order.begin(), order.end());
    order.erase( unique(order.begin(), order.end()), order.end() );

    for (auto it = x.begin(); it != x.end(); it++) {
        auto it2 = lower_bound(order.begin(), order.end(), *it);
        *it = distance(order.begin(), it2);
    }
}