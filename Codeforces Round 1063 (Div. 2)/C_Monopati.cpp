#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

int32_t main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        int max_val = 2 * n;

        vector<int> pref_min1(n + 1);
        vector<int> pref_max1(n + 1);
        vector<int> suff_min2(n + 2);
        vector<int> suff_max2(n + 2);

        pref_min1[0] = max_val + 1;
        pref_max1[0] = 0;
        suff_min2[n + 1] = max_val + 1;
        suff_max2[n + 1] = 0;

        for (int k = 1; k <= n; ++k) {
            pref_min1[k] = min(pref_min1[k - 1], a[0][k - 1]);
            pref_max1[k] = max(pref_max1[k - 1], a[0][k - 1]);
        }

        for (int k = n; k >= 1; --k) {
            suff_min2[k] = min(suff_min2[k + 1], a[1][k - 1]);
            suff_max2[k] = max(suff_max2[k + 1], a[1][k - 1]);
        }

        vector<int> min_M(max_val + 2, max_val + 1);

        for (int k = 1; k <= n; ++k) {
            int mk = min(pref_min1[k], suff_min2[k]);
            int Mk = max(pref_max1[k], suff_max2[k]);
            min_M[mk] = min(min_M[mk], Mk);
        }

        for (int l = max_val; l >= 1; --l) {
            min_M[l] = min(min_M[l], min_M[l + 1]);
        }

        int ans = 0;
        for (int l = 1; l <= max_val; ++l) {
            int M_star = min_M[l];
            if (M_star <= max_val) {
                ans += (max_val - M_star + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}