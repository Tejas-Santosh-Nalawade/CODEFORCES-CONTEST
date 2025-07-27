#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n);
    for (auto &x : b) cin >> x;

    ll target = b[0];
    for (int i = 1; i < n; ++i) {
        if (b[i] > 2 * target - 1) {
            cout << "NO" << "\n";
            return;
        }
        target = min(target, b[i]);
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}