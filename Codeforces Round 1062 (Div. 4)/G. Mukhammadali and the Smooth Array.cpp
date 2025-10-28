#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), costs(n);
    for (auto &x : a) cin >> x;
    for (auto &x : costs) cin >> x;

    vector<ll> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    // dp[j] → min cost to make prefix non-decreasing with b[i] = vals[j]
    vector<ll> dp(m);
    for (int j = 0; j < m; j++)
        dp[j] = (a[0] == vals[j] ? 0 : costs[0]);

    // iterate each position
    for (int i = 1; i < n; i++) {
        vector<ll> newdp(m);
        ll pref = LLONG_MAX;
        for (int j = 0; j < m; j++) {
            pref = min(pref, dp[j]);
            ll add = (a[i] == vals[j] ? 0 : costs[i]);
            newdp[j] = pref + add;
        }
        dp.swap(newdp);
    }

    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    fastio();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
