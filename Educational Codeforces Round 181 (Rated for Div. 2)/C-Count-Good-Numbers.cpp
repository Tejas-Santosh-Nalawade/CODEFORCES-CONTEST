#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll prefix_good[211];

void precompute() {
    prefix_good[0] = 0;
    for (int i = 1; i <= 210; ++i) {
        bool is_good = (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0);
        prefix_good[i] = prefix_good[i - 1] + (is_good ? 1 : 0);
    }
}
ll count_good_up_to(ll n) {
    if (n == 0) {
        return 0;
    }
    
    ll num_blocks = n / 210;
    ll remainder = n % 210;
    
    ll total_count = num_blocks * 48;
    total_count += prefix_good[remainder];
    
    return total_count;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll result = count_good_up_to(r) - count_good_up_to(l - 1);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}