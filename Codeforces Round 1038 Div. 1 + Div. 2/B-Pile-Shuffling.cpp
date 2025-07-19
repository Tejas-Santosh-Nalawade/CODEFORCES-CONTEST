#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll op = 0;
    
    for (int i = 0; i < n; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll mp = 0;
        if (b > d) {
            mp += (b - d);
            mp += a;
        } else {
            if (a > c) {
                mp += (a - c);
            }
        }
        op += mp;
    }
    cout << op << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}