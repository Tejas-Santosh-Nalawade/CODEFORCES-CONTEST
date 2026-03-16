#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    
    int ans = 0;
    int max_count = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x >= max_count){
            max_count = x;
            ans++;
        }
    }
    cout << ans << "\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}