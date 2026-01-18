#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;cin>>n;
    for(int i=1; i<=n; i++){
        cout<<i<<(i== n ? "" : " ");
    }
    cout<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
