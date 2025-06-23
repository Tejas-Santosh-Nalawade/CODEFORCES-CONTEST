#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int a, x, y;
        cin >> a >> x >> y;
        bool found = false;
        
        for (int b = 1; b <= 100; ++b) {
            if (b == a) continue;

            if (abs(b - x) < abs(a - x) && abs(b - y) < abs(a - y)) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}
