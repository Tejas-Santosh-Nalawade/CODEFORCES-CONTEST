#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){   
    int n; cin >> n;

    int k = 1;
    int val  = n;

    for(int i=2; i*i<= val; i++){
        if(val % i ==0){
            k*=i;
            while(val % i ==0){
                val /=i;
            }
        }
    }
    if(val > 1){
        k*=val;
    }
    cout<<k<<"\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
