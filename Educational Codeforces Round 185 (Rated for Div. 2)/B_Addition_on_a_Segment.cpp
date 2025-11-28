#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin >> n;
    
    int sum = 0;
    int count = 0;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        if(x > 0) {
            count++;
        }
    }  
    int ans = min(count, sum - n + 1);
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}