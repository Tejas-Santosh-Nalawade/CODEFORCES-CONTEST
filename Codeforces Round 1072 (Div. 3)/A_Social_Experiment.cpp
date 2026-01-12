#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;

    if(n == 2){
        cout<<2<<"\n";
        return;
    }
    if(n == 3){
        cout<<3<<"\n";
        return;
    }
    if(n%2 == 0){
        cout<<0<<"\n";
    }
    else{
        cout<<1<<"\n";
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while (tt--) solve();
}
