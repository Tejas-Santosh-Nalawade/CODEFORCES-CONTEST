#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    
    int total = 0;

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) {
        cin >> b[i];
        total^= (a[i] ^ b[i]);
    }
    if(total == 0){
        cout << "Tie" << endl;
        return;
    }

    int msb = -1;
    for(int bit = 20; bit >= 0; bit--){ 
        if((total >> bit) & 1){
            msb = bit;
            break;
        }
    }

    int index = -1; 
    
    for(int i = n-1; i >= 0; i--){
        int bit_a = (a[i] >> msb) & 1;
        int bit_b = (b[i] >> msb) & 1;
        
        if(bit_a != bit_b){
            index = i + 1; 
            break;
        }
    }

    if(index % 2 != 0){
        cout << "Ajisai" << endl;
    } else {
        cout << "Mai" << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
