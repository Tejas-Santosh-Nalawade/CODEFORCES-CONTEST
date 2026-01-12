#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << 0 << "\n";
        return;
    }

    if (k > n) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 1; i <= 32; i++) {
        int denom  = (1LL << i);
        int version1 = n / denom;
        int version2 = (n + denom - 1) / denom;

        if (version1 == k || version2 == k) {
            cout << i << "\n";
            return;
        }

        if (version2 < k) {
            cout << -1 << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}