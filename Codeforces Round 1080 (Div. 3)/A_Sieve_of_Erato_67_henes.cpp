#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;cin>>n;
    bool found = false;

    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(a==67){
            found = true;
        }

    }
    if(found){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}