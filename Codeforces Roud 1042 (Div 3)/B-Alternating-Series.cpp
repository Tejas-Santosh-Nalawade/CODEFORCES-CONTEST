#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) cout << 3 << " ";
            else cout << -1 << " ";
        }
        cout << "\n";
    } else {
        for (int i = 1; i <= n - 2; ++i) {
            if (i % 2 == 0) cout << 3 << " ";
            else cout << -1 << " ";
        }
        cout << -1 << " " << 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
