#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int count_0 = 0;
    int count_1 = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == 0) count_0++;
        if(a[i] == 1) count_1++;
    }

        if(count_0 == 0){
            cout<<"NO"<<"\n";
        }
        else if(count_1 == 0 && count_0 > 1){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }   
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
