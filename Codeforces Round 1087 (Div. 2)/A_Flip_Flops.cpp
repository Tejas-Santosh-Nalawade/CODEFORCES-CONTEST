#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,c,k;
    cin>>n>>c>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    for(int i=0; i<n; i++){
        if(c >= a[i]){
            int val = min(k, c-a[i]);
            k-= val;
            c+=a[i]+val;
        }
        else{
            break;
        }
    }
    cout<<c<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}