#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int l,a,b;
    cin>>l>>a>>b;

    int g = __gcd(b,l);
    
    int final_ans = l - 1;
    int target_value = a % g;

    int current_value = final_ans % g;

    if(current_value >= target_value){
        final_ans -= (current_value - target_value);
    }
    else{
        final_ans -=  (current_value + g - target_value);
    }
    cout<<final_ans<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
