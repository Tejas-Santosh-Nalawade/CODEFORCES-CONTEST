#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

void solve() {
    ll n, a;
    cin >> n >> a;

    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    ll bestB = 1337;
    ll best = 0;

    auto it1 = upper_bound(v.begin(), v.end(), a);
    int j = it1 - v.begin();
    if (j < n) {
        ll score = n - j;
        ll b1 = 2LL * v[j] - a - 1;
        if (score > best) {
            best = score;
            bestB = b1;
        }
    }

    auto it2 = lower_bound(v.begin(), v.end(), a);
    int k = (it2 - v.begin()) - 1;
    if (k >= 0) {
        ll score = k + 1;
        ll b2 = 2LL * v[k] - a + 1;
        if (b2 >= 0 && score > best) {
            best = score;
            bestB = b2;
        }
    }
    ll cutoff = (a - 1) / 2;
    auto it3 = upper_bound(v.begin(), v.end(), cutoff);
    ll score0 = it3 - v.begin();
    if (score0 > best) {
        best= score0;
        bestB = 0;
    }

    cout << bestB << endl;
}

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) solve();

    return 0;
}
