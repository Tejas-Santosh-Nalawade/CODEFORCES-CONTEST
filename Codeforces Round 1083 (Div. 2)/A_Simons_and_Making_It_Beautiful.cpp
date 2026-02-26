#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){   
    int n; cin >> n;
    vector<int> p(n);

    int max_indx = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        if(p[i]== n){
            max_indx = i;
        }
    }

    swap (p[0] , p[max_indx]);

    for(int i=0; i<n; i++){
        cout<<p[i]<<(i == n - 1 ? "": " ");
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
