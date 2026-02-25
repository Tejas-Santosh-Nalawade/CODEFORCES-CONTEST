#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,d;
    cin>> n >> m >> d;

    int max_box = (d/m) + 1 ;

    int tower  = ( n + max_box -1) / max_box;

    cout<<tower<<"\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}