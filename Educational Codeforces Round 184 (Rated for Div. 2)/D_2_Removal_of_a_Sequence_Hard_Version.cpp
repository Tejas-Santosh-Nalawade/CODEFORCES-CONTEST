#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using ll128 = __int128;

ll128 read128() {
    string s; 
    cin >> s;
    ll128 x = 0;
    bool neg = false;
    int idx = 0;

    if (s[0] == '-') { neg = true; idx = 1; }

    for (; idx < (int)s.size(); idx++) {
        x = x * 10 + (s[idx] - '0');
    }

    return neg ? -x : x;
}

void print128(ll128 x) {
    if (x == 0) { cout << 0; return; }
    if (x < 0) { cout << "-"; x = -x; }
    string s;
    while (x > 0) {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve() {
    ll128 x = read128();
    ll128 y = read128();
    ll128 k = read128();

    if (y == 1) {
        cout << -1 << endl;
        return;
    }

    ll128 x_orig = x;
    ll128 n = (ll128)1000000000000LL;

    // forward simulate n
    while (x > 0) {
        ll128 q = n / y;
        if (q == 0) break;
        ll128 r = n % y;

        ll128 s = (r / q) + 1;
        if (s > x) s = x;

        n = n - s * q;
        x -= s;
    }

    ll128 n_final = n;
    if (k > n_final) {
        cout << -1 << endl;
        return;
    }

    ll128 m = y - 1;
    x = x_orig;

    while (x > 0) {
        ll128 q = (k - 1) / m;
        if (q == 0) break;

        ll128 r = (k - 1) % m;

        ll128 s = (m - r + q - 1) / q;
        if (s > x) s = x;

        k = k + s * q;
        x -= s;
    }

    print128(k);
    cout << endl;
}

int main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) solve();

    return 0;
}
