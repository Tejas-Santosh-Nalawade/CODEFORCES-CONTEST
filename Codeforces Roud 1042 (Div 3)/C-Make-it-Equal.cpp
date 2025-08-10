#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; long long k; cin>>n>>k;
    vector<long long>a(n),b(n);
    for(int i=0;i<n;i++){long long v;cin>>v;long long r=v%k;a[i]=min(r,k-r);}
    for(int i=0;i<n;i++){long long v;cin>>v;long long r=v%k;b[i]=min(r,k-r);}
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    cout<<(a==b?"YES\n":"NO\n");
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;while(tt--)solve();
}
