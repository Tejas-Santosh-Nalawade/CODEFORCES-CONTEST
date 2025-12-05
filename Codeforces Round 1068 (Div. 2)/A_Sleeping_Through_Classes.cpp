#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k;
    string s;
    cin>>s;
    int count = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i]== '1') {
            count = k;
        }
        else {
            if(count > 0){
                count--;
            }
            else{
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
