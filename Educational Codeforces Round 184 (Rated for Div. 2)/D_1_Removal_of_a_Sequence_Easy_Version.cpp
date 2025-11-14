#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    if (y == 1) {
        cout << -1 << endl;
        return;
    }

    ll n = 1e12L;

    for (int i = 0; i < x; i++) {
        n = n - n / y;
    }

    ll length = n;

    if (k > length) {
        cout << -1 << endl;
        return;
    }

    ll cur = k;
    ll sequence = y - 1;

    for (int i = 0; i < x; i++) {
        cur = cur + (cur - 1) / sequence;
    }

    cout << cur << endl;
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
