#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> total(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total[a[i]]++;
        }

        bool ok = true;
        vector<int> target(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (total[i] % k != 0) {
                ok = false;
                break;
            }
            target[i] = total[i] / k;
        }

        if (!ok) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = 0;
        vector<int> window(n + 1, 0);
        int r = 0;

        for (int l = 0; l < n; l++) {
            while (r < n && window[a[r]] < target[a[r]]) {
                window[a[r]]++;
                r++;
            }
            ans += (r - l);
            window[a[l]]--;
        }

        cout << ans << "\n";
    }

    return 0;
}
