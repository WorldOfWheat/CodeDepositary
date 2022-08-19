#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n) break;
        if (n == 1) {
            cout << "Discarded cards: " << endl;
            cout << "Remaining card: 1" << endl;
            continue;
        }
        queue<int> cards;
        vector<int> drop;
        for (int i = 0; i < n; i++) {
            cards.push(i+1);
        }
        while (cards.size() != 1) {
            drop.push_back(cards.front());
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        cout << "Discarded cards: " << drop.front();
        for (int i = 1; i < drop.size(); i++) {
            cout << ", " << drop[i];
        }
        cout << endl;
        cout << "Remaining card: " << cards.front() << endl;
    }

    return 0;
}
