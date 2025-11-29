#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin>>n;
    unordered_map<int,int> count;

    for(int i=0;i<2*n;i++){
        int x; cin>>x;
        count[x]++;
    }
    int even=0,odd=0;
    for(auto c: count){
        if(c.second&1) odd++;
        else even++;
    }

    if(even > n ){
        cout<<2LL * n + odd<< "\n";

    }
    else{
        int ans = 2LL * even + odd;
        if(odd == 0 && (n&1)!=(even&1)){
            ans -= 2;
        }
        cout<<ans<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
