#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    multiset<long long> bags;
    for (int i = 0; i < n; ++i) {
        long long weight;
        cin >> weight;
        bags.insert(weight);
    }

    int coins_spent = 0;
    long long day = 0;

    while (!bags.empty()) {
        day++;
        
        long long multiplier = 1LL << (day - 1);
        long long limit = c / multiplier;

        auto it = bags.upper_bound(limit);

        if (it == bags.begin()) {
            coins_spent++;
            auto largest_it = bags.end();
            largest_it--;
            bags.erase(largest_it);
        } else {
            it--;
            bags.erase(it);
        }
    }

    cout << coins_spent << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
