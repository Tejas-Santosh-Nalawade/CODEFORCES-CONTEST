#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int s,k,m;
    cin>>s>>k>>m;

    if(k >= s){
        int remainder = m % k;
        if(remainder == 0){
            cout<<s<<"\n";
        }
        else{
            cout<<max(0LL, s - remainder)<<"\n";
        }
    }
    else{
        int remainder = m % (2 * k);
        if(remainder == 0){
            cout<<s<<"\n";
        }
        else if(remainder < k){
            cout<<s - remainder<<"\n";
        }
        else{
            cout<<2 * k - remainder<<"\n";
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
