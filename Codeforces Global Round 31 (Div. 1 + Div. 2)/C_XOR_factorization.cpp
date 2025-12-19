#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int val, len;
    if (!(cin >> val >> len)) return;

    if (len % 2 != 0) {
        for (int i = 0; i < len; ++i) {
            cout << val << (i == len - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        for (int i = 0; i < len - 2; ++i) {
            cout << val << " ";
        }

        int best_x = val, best_y = 0;
        int max_total = val;

        for (int bit = 30; bit >= 0; --bit) {
            if ((val >> bit) & 1) {
                int tx = 0, ty = 0;
                

                tx = (val >> (bit + 1)) << (bit + 1);
         
                ty = (1LL << bit);

                for (int j = bit - 1; j >= 0; --j) {
                    if ((val >> j) & 1) {
         
                        tx |= (1LL << j);
                    } else {
                        tx |= (1LL << j);
                        ty |= (1LL << j);
                    }
                }

                if (tx <= val && ty <= val) {
                      if (tx + ty > max_total) {
                        max_total = tx + ty;
                        best_x = tx;
                        best_y = ty;
                    }
                }
            }
        }
        cout << best_x << " " << best_y << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; 
    if (!(cin >> tt)) return 0;
    while (tt--) {
        solve();
    }
    return 0;
}