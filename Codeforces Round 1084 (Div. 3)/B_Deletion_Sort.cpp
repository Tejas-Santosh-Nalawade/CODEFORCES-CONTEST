#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    if(is_sorted(a.begin(),a.end())){
        cout<<n<<"\n";
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