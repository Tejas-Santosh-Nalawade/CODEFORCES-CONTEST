#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n, x;
    cin >> n >> x;
    
    int simple = 0; 
    int jump = -2e18;
    
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        simple += (b - 1) * a;
        
        int gain = (a * b) - c;

        jump = max(jump, gain);
    }

    if (simple >= x) {
        cout << 0 << "\n";
    } else {
        if (jump <= 0) {
            cout << -1 << "\n";
        } else {
            int neecseary = x - simple;
            int ans = (neecseary + jump - 1) / jump;
            cout << ans << "\n";
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}