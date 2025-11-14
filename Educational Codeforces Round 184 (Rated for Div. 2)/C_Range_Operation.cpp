    #include <bits/stdc++.h>
    using namespace std;

    #define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
    using ll = long long;
    #define endl '\n'

    void solve() {
        int n;
        cin >> n;
        vector<ll> a(n + 1), pref(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        ll best = 0;
        ll max_gain = 0;

        for (int r = 1; r <= n; r++) {

            ll rpart = 1LL * r * r + r - pref[r];
            ll gain = best + rpart;
            max_gain = max(max_gain, gain);
            ll j = r;
            ll jpart = pref[j] - j - 1LL * j * j;
            best = max(best, jpart);
        }

        ll total = pref[n] + max(0LL, max_gain);
        cout << total << endl;
    }

    int main() {
        fastio();

        int tt;
        cin >> tt;
        while (tt--) {
            solve();
        }
        return 0;
    }