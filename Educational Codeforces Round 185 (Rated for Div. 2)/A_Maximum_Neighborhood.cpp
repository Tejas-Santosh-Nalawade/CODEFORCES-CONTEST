#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin>>n;
    if(n == 1) cout<<1<<endl;
    else if (n == 2) cout<<9<<endl;
    else if( n == 3) cout<< 29<<endl;
    else if(n== 4) cout<<56<<endl;

    else{
        int val = n * n - n -1 ;
        cout<<5* val <<endl;  
    }

}       

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
