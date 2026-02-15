#include<bits/stdc++.h>
using namespace std;
#define int long long

int odd_part(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x;
}

void solve(){
    int n; 
    cin >> n; 
    bool find = true; 
    for(int i = 1; i <= n; ++i){
        int a; 
        cin >> a;
        if(find) {
            if(odd_part(a) != odd_part(i)){
                find = false;
            }
        }
    }
    if(find) cout << "YES"<<"\n";
    else cout << "NO"<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}