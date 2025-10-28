#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<long long>arr(n);
    
    int parity_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        parity_sum += (arr[i] & 1);
    }

    if (parity_sum == 0 || parity_sum == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << (i + 1 == n ? '\n' : ' ');
        }
    } else {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            cout << arr[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}

int32_t main() {
    fastio();

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
