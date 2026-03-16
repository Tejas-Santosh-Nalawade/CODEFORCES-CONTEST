#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            cout<<i+1<<" ";
            cout<<"\n";
            return;
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