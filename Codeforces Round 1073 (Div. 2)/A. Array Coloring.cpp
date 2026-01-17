#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int parity = (a[0] + 0) % 2;
    
    bool complete = true;
    
    for (int i = 1; i < n; i++) {
        if ((a[i] + i) % 2 != parity) {
            complete = false;
            break;
        }
    }

    if (complete) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
