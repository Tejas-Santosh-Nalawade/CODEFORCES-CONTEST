#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0; i<n; i++){
        int great = 0;
        int small = 0;
        for(int j=i+1; j<n; j++){
            if(a[j] > a[i]){    
                great++;
            }
            else if(a[j] < a[i]){
                small++;
            }
        }    
        cout<<max(great,small)<<(i==n-1?"":" ");
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